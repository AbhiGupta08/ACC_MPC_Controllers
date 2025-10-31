### This file will contain functions for creating Model Predictive Controls Matrices for UWAFT's MPC ACC controls code
###### By Abhi Gupta

import numpy as np
import osqp # The solver being used for the MPC optimization problem
from scipy.linalg import block_diag # to create block diagonal matrices

# Function to create the augmented discrete state space system with delta u (control deviation) as control input; 
# takes in continuous time A, B matrices of system, and timestep (Ts)
def discretize_and_augment_sys(Ac, Bc, Ts):
    # Extracting num of states and inputs
    n_states = Ac.shape[0]
    n_ctrl = Bc.shape[1]

    # Discretizing system matrices with Euler discretization
    Ad = np.eye(n_states) + Ac*Ts
    Bd = Bc*Ts
    Cd = np.eye(n_states) # The ouputs are equal to the full original state vector

    n_out = Cd.shape[0] # Number of outputs

    # Augmenting the discretized system from above to have delta u as control input and state vector zeta[k] = [x[k]; u[k-1]]
    Ad_aug = np.block([[Ad, Bd], [np.zeros((n_ctrl, n_states)), np.identity(n_ctrl)]])
    Bd_aug = np.vstack((Bd, np.identity(n_ctrl)))
    Cd_aug = np.hstack((Cd, np.zeros((n_out, n_ctrl))))
    return Ad_aug, Bd_aug, Cd_aug

# Function to create batch matrices needed for MPC future state and control deviation prediction
# Takes in discrete A, B, and C system matrices and MPC prediction horizon Np
def mpc_batch_matrix_create(A, B, C, Np):
    # extracting number of augmented system states, inputs, and outputs
    nx = A.shape[0] 
    nu = B.shape[1]
    ny = C.shape[0]

    # Pre-computing the powers of A for batch matrix creation
    # this loop creates Ad_powers = [A^0; A^1; ...; A^Np] where A^0 = identity so that it is easy to perform A^(k+1) = A^K * A recursion 
    Ad_powers = [np.eye(nx)]
    for _ in range(Np):
        Ad_powers.append(A @ Ad_powers[-1])
    
    # Ad_powers = np.stack(Ad_powers) # Converting back to numpy array from list; not needed
    
    ## Creating batch matrices
    # Stacked output matrix F = [C Ad; C Ad^2; ...; C Ad^Np] 
    # Multiplies C with each entry in Ad_powers starting AFTER the A^0 term
    F = np.zeros((Np * ny, nx))
    for k in range(1, Np + 1):
        row = slice((k - 1) * ny, k * ny)
        F[row, :] = C @ Ad_powers[k]

    # Block Toeplitz Phi with full control horizon (Nc = 0 → no truncation)
    Phi = np.zeros((Np * ny, Np * nu))
    for k in range(1, Np + 1):
        row = slice((k - 1) * ny, k * ny)
        for j in range(k):
            col = slice(j * nu, (j + 1) * nu)
            Phi[row, col] = C @ Ad_powers[k - 1 - j] @ B
    
    state_batch = F
    ctrl_batch = Phi
    return state_batch, ctrl_batch

# Function to create matrices for input constraints on applied/commanded acceleration < |a_max| to satisfy format lb < A_constraints*x < ub
# Takes in a_max, u[k-1], delta_U[k-1], Np as inputs
def applied_accel_constraints_create(Np, a_applied_max, u_prev, delta_U_prev):
    # Requires rebuilding the full U[k-1] = [u[k-1], u[k-1+1], ..., u[k-1+Np-1]] control vector over the full prediction/control horizon
    U_prev = np.zeros((Np,1))
    U_prev[0] = u_prev # making first element of U[k-1] equal to the known u[k-1]
    u_prev_plus_i = u_prev
    for i in range(Np-1):
        u_prev_plus_i = u_prev_plus_i + delta_U_prev[i+1]
        U_prev[i+1] = u_prev_plus_i
    # print("U[k-1]", U_prev)

    # Since a_max will be applied to all control inputs over the full prediction/control horizon
    a_app_MAX = a_applied_max*np.ones((Np,1))
    a_app_MIN = -a_applied_max*np.ones((Np,1))
    
    lb_input = a_app_MIN - U_prev
    ub_input = a_app_MAX - U_prev
    A_input = np.block([[np.eye(Np), np.zeros((Np,Np)), np.zeros((Np,Np)), np.zeros((Np,Np))]])
    
    # print("lb_input", lb_input)
    # print("ub_input", ub_input)
    # print("A_inpt", A_input)
    return lb_input, ub_input, A_input

# Function to create matrices for input deviation (delta u) which end up being related to jerk of the system
# Also placing limits on the slack variables to be non-negative
# Takes in jerk max limit, sample time (Ts), prediction horizon (Np); delta_accel_applied < |Jmax*Ts|
def jerk_slack_constraints(jerk_max_lim, Np, Ts):
    # Since jerk constraints will be applied to the full predicted control deviation vector delta_U[k]
    J_MAX = (jerk_max_lim*Ts)*np.ones((Np,1))
    J_MIN = (-jerk_max_lim*Ts)*np.ones((Np,1))

    lb_jerk_slack = np.vstack((J_MIN, np.zeros((3*Np,1))))
    ub_jerk_slack = np.vstack((J_MAX, 1000*np.ones((3*Np,1))))         
    A_jerk_slack = np.block([[np.eye(Np), np.zeros((Np,Np)), np.zeros((Np,Np)), np.zeros((Np,Np))], 
                             [np.zeros((Np,Np)), np.eye(Np), np.zeros((Np,Np)), np.zeros((Np,Np))],
                             [np.zeros((Np,Np)), np.zeros((Np,Np)), np.eye(Np), np.zeros((Np,Np))],
                             [np.zeros((Np,Np)), np.zeros((Np,Np)), np.zeros((Np,Np)), np.eye(Np)]])
    
    # print("lb_jerk+_salc", lb_jerk_slack)
    # print("ub_jerk_slack", ub_jerk_slack)
    # print("A_jerk_slack", A_jerk_slack)
    return lb_jerk_slack, ub_jerk_slack, A_jerk_slack

# Function to create the output constraints of the system on host vehicle velocity and acceleration
def output_constraints_create(driver_set_speed, host_accel_max, state_batch, ctrl_batch, curr_state_vec, Np):
    # Need to create the batch matrices for extracting just the predicted outputs for host velocity and acceleration states only
    T_vh = np.kron(np.eye(Np), np.array([[1, 0, 0, 0]])) # Mask to extract all v_host states over prediction horizon
    T_ah = np.kron(np.eye(Np), np.array([[0, 1, 0, 0]])) # Mask to extract all a_host states over prediction horizon
    # T_vh = np.kron(np.eye(Np), np.array([[1, 0, 0]])) 
    # T_ah = np.kron(np.eye(Np), np.array([[0, 1, 0]]))

    st_btch_vh =  T_vh @ state_batch # For matrix multiplication of T_vh * state_batch; np.dot(T_vh,state_batch) also works
    ctr_btch_vh = T_vh @ ctrl_batch # same result as before of T_vh * ctrl_batch with different notation
    
    st_btch_ah = np.dot(T_ah,state_batch)
    ctr_btch_ah = np.dot(T_ah,ctrl_batch)

    lb_out = np.vstack((-1000*np.ones((2*Np,1)), -1000*np.ones((2*Np,1))))

    # print("drive", driver_set_speed*np.ones((Np,1)))
    # print("setbatch", st_btch_vh @ curr_state_vec)
    # print(driver_set_speed*np.ones((Np,1)) - (st_btch_vh @ curr_state_vec))

    ub_vh = np.vstack((driver_set_speed*np.ones((Np,1)) - (st_btch_vh @ curr_state_vec), st_btch_vh @ curr_state_vec))
    ub_ah = np.vstack((host_accel_max*np.ones((Np,1)) - (st_btch_ah @ curr_state_vec), host_accel_max*np.ones((Np,1)) + (st_btch_ah @ curr_state_vec)))
    ub_out = np.vstack((ub_vh, ub_ah))

    A_vh = np.block([[ctr_btch_vh, -np.eye(Np), np.zeros((Np,Np)), np.zeros((Np,Np))], [-ctr_btch_vh, np.zeros((Np,Np)), np.zeros((Np, Np)), np.zeros((Np,Np))]])
    A_ah = np.block([[ctr_btch_ah, np.zeros((Np,Np)), -np.eye(Np), np.zeros((Np,Np))], [-ctr_btch_ah, np.zeros((Np,Np)), np.zeros((Np,Np)), -np.eye(Np)]])
    A_out = np.vstack((A_vh, A_ah))

    # print("lb_out", lb_out)
    # print("ub_out", ub_out)
    # print("A_out", A_out)
    return lb_out, ub_out, A_out

# Function to create the hessian (H) and f matrices derived from the batch matrices and costs for states (q), control inputs (r), and slack variables (rho)
def cost_matrices_create(state_batch, ctrl_batch, curr_state_vec, Np, q_vh, q_ah, q_dfoll_err, q_vrel, r_delta_a_cmd, rho_vh_max, rho_ah_max, rho_ah_min):
    # Creating the Qbar and Rbar matrices
    Q = np.diag([q_vh, q_ah, q_dfoll_err, q_vrel])
    R = np.diag([r_delta_a_cmd])

    Q_bar = np.kron(np.eye(Np), Q)
    R_bar = np.kron(np.eye(Np), R)
    
    H = block_diag(2*(ctrl_batch.T @ Q_bar @ ctrl_batch + R_bar), 2*rho_vh_max*np.eye(Np), 2*rho_ah_max*np.eye(Np), 2*rho_ah_min*np.eye(Np)) # The hessian for the solver
    f = np.vstack([2*ctrl_batch.T @ Q_bar @ state_batch @ curr_state_vec, np.zeros((3*Np, 1))])
    H = 0.5 * (H + H.T) + 1e-8 * np.eye(H.shape[0]) # Tiny regularizer to ensure positive-definite

    # # Scaling the H and f matrices in the event the norm is too large and OSQP has trouble converging
    # norm_H = np.linalg.norm(H.data if hasattr(H, "data") else H, np.inf)
    # norm_f = np.linalg.norm(f, np.inf)

    # # choose overall scaling factor = largest of the two (avoid divide by 0)
    # scale = max(norm_H, norm_f, 1.0)

    # # apply scaling
    # H_scaled = H / scale
    # f_scaled = f / scale
    # return H_scaled, f_scaled, scale     # return scale if you want to track it
    return H, f