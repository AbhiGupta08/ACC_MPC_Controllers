# This program creates the base discrete A, B, and C system matrices for the adaptive cruise control system for UWAFT's Cadillac LYRIQ
# In RTMaps this bridge component takes in current LYRIQ velocity feedback to create augmented state space system matrices for the ACC state space system with control deviation (delta_u) as input
# This bridge component then feeds into the batch matrix creation bridge component

import rtmaps.core as rt
import rtmaps.types
from rtmaps.base_component import BaseComponent  # base class
from rtmaps.types import Matrix  # import this so can output matrices directly without RTMaps converting to long array
import numpy as np
from scipy.linalg import block_diag # to create block diagonal matrices

import importlib # Use this code library to reload the ACC_MPC_utils code at bridge component startup
import ACC_mpc_utils as mpc # Abhi's ACC MPC utils file for this system
import ACC_osqp_utils as osqp_utils # Utils file created with OSQP solver for the optimization problem

# Python class that will be called from RTMaps.
class rtmaps_python(BaseComponent):
    
    # Constructor has to call the BaseComponent parent class
    def __init__(self):
        BaseComponent.__init__(self)  # call base class constructor

    # Dynamic is called frequently: When loading the diagram; When connecting or disconnecting a wire; Here you create your inputs, outputs and properties
    def Dynamic(self):
        # Adding system properties/parameters here
        self.add_property("mass", 2630.84) # LYRIQ mass; kg
        self.add_property("Cw", 0.30356) # LYRIQ wind resistance coefficient
        self.add_property("Aw", 2.73) # windward area of LYRIQ; m^2
        self.add_property("actuator_time_delay", 0.02) # time delay associated with actuators on LYRIQ; s
        self.add_property("sample_time", 0.05) # MPC sample time; s
        self.add_property("prediction_horizon", 2) # MPC prediction horizon; sample steps

        # Defining MPC constraints lmiits as component properties
        self.add_property("applied_accel_max", 3.5) # acceleration control signal limit
        self.add_property("host_accel_max", 3.0) # experienced acceleration maximum limit
        self.add_property("jerk_max", 5.0) # vehicle jerk maximum limit

        # Defining the weights for states (q)
        self.add_property("q_vh", 0.0) # Weight for the host velocity state
        self.add_property("q_ah", 5.0) # weight for host acceleration state
        self.add_property("q_dfoll_err", 5.0) # Weight for the following distance error state
        self.add_property("q_vrel", 5.0) # weight for relative velocity state between lead and host
        
        # Defining weight for control deviation (r) as property
        self.add_property("r_a_delta_cmd", 10.0) # weight on applied acceleration deviation

        # Weights for the slack variables (rho)
        self.add_property("rho_vh_max", 50.0) # Weight on slack applied to host velocity maximum limit
        self.add_property("rho_ah_max", 25.0) # Weight for slack on host acceleration maximum limit
        self.add_property("rho_ah_min", 25.0) # Weight for slack on host accel minimum limit
        
        # Adding current timestep LYRIQ host velocity (vh) feedback
        self.add_input("host_velocity", rtmaps.types.FLOAT64)
        self.add_input("host_accel", rtmaps.types.FLOAT64)
        self.add_input("foll_dist_error", rtmaps.types.FLOAT64)
        self.add_input("relative_velocity", rtmaps.types.FLOAT64)
        self.add_input("driver_set_speed", rtmaps.types.FLOAT64)
        
        # # Adding the discrete system matrices as outputs from this block
        # self.add_output("A_aug", rtmaps.types.MATRIX)
        # self.add_output("B_aug", rtmaps.types.MATRIX)
        # self.add_output("C_aug", rtmaps.types.MATRIX)

        # Commanded vehicle acceleration is the output of the MPC system for ACC
        self.add_output("a_cmd", rtmaps.types.FLOAT64)
        self.add_output("seen_dist", rtmaps.types.FLOAT64)

# Birth() will be called once at diagram execution startup; can initialize variables here that would persist (keep their last value) between calls to Core() 
    def Birth(self):
        importlib.reload(mpc) # reloading the mpc utils file code so that latest changes are reflected
        importlib.reload(osqp_utils) # reloading the ACC osqp utils file code

        # Creating "persistent" variables
        self.first_call = True
        self.u_prev = 0.0 # variable to store the control signal applied at each timestep
        
        Np = self.get_property("prediction_horizon")
        # Variable to store the full predicted delta_U[k-1] control signal from the previous iteration; Use to find the full U[k-1]
        self.delta_U_prev = np.zeros((Np,1)) 

        print("Passing through Birth()")

# Core() is called every time you have a new inputs available, depending on your chosen reading policy
    def Core(self):
        # Extracting feedback from the python bridge component's inputs
        vh = self.inputs["host_velocity"].ioelt.data
        ah = self.inputs["host_accel"].ioelt.data
        derr = self.inputs["foll_dist_error"].ioelt.data
        vrel = self.inputs["relative_velocity"].ioelt.data
        drv_set_spd  = self.inputs["driver_set_speed"].ioelt.data
        
    
        # Creating parameters or extracting from bridge component properties for determining the continuous time system matrices
        m = self.get_property("mass")
        Cw = self.get_property("Cw")
        Aw = self.get_property("Aw")
        act_time_del = self.get_property("actuator_time_delay")
        Ts = self.get_property("sample_time")
        Np = self.get_property("prediction_horizon")
        air_dens = 1.206 # air density; kg/m^3 

        # Pulling properties that describe constraint limits
        a_app_max = self.get_property("applied_accel_max")
        ah_max = self.get_property("host_accel_max")
        jerk_max = self.get_property("jerk_max")

        # Pulling properties that describe the weights for MPC costs
        q_vh = self.get_property("q_vh") # Weights on states
        q_ah = self.get_property("q_ah")
        q_dfoll_err = self.get_property("q_dfoll_err")
        q_vrel = self.get_property("q_vrel")

        r_a_delta_cmd = self.get_property("r_a_delta_cmd") # Weight on input deviation

        rho_vh_max = self.get_property("rho_vh_max") # Weight on slack variables
        rho_ah_max = self.get_property("rho_ah_max") 
        rho_ah_min = self.get_property("rho_ah_min")

        # pulling the previous control signal from u_prev and delta_U_prev variables initialized in Birth()
        u_prev = self.u_prev
        delta_U_prev = self.delta_U_prev

        # Assembling the current augmented state vector with states zeta[k] = [vh[k]; ah[k]; derr[k]; vrel[k]; u[k-1]]
        curr_state_vec = np.vstack((vh, ah, derr, vrel, u_prev))

        # Calculating the continuous time A and B matrices with states x[k] = [vh[k]; ah[k]; derr[k]; vrel[k]] and u[k] = a_cmd[k]
        Ac = np.array([ [(-air_dens*Aw*Cw*vh)/(2*m), 1, 0, 0], [0, -1/act_time_del, 0, 0], [0,0,0,-1], [(air_dens*Aw*Cw*vh)/(2*m), -1, 0, 0] ])
        Bc = np.array([ [0], [1/act_time_del], [0], [0] ])
        
        # utils function to create the augmented state space system matrices with delta u as control signal and zeta[k] as augmented state vector
        Ad_aug, Bd_aug, Cd_aug = mpc.discretize_and_augment_sys(Ac=Ac, Bc=Bc, Ts=Ts)
        
        ############### testicling shietetetet
        # A_test = np.array([ [1,2,3], [1,2,3], [1,2,3]  ])
        # B_test = np.array([ [2], [3],[4] ])
        # C_test = np.array([ [1,0,0], [0,1,0], [0,0,1]])
        # mpc.mpc_batch_matrix_create(A_test, B_test, C_test, 2)
        
        # state_batch, ctrl_batch = mpc.mpc_batch_matrix_create(A=A_test, B=B_test, C=C_test, Np=3)
        # lb_input, ub_input, A_input = mpc.applied_accel_constraints_create(Np=3, a_applied_max=a_app_max, u_prev=0.4, delta_U_prev=np.ones((3,1))*2.5)
        # lb_jerk_slack, ub_jerk_slack, A_jerk_slack = mpc.jerk_slack_constraints(jerk_max_lim=jerk_max, Np=3, Ts=Ts)
        # lb_out, ub_out, A_out = mpc.output_constraints_create(driver_set_speed=drv_set_spd, host_accel_max=ah_max, state_batch=state_batch, ctrl_batch=ctrl_batch, curr_state_vec=0.8*np.ones((3,1)), Np=3)
        ##################

        # utils function to create the batch matrices to perform the MPC prediction
        state_batch, ctrl_batch = mpc.mpc_batch_matrix_create(A=Ad_aug, B=Bd_aug, C=Cd_aug, Np=Np)

        # Creating the matrices for the constraints to be applied to the solver in the form lower bound < A_ineq * U[k] < upper bound
        # constraints on applied acceleration 
        lb_input, ub_input, A_input = mpc.applied_accel_constraints_create(Np=Np, a_applied_max=a_app_max, u_prev=u_prev, delta_U_prev=delta_U_prev)
        # constraints on jerk (control deviation: delta_u) and the slack variables
        lb_jerk_slack, ub_jerk_slack, A_jerk_slack = mpc.jerk_slack_constraints(jerk_max_lim=jerk_max, Np=Np, Ts=Ts)
        # constraints on the outputs of host velocity and accelerations
        lb_out, ub_out, A_out = mpc.output_constraints_create(driver_set_speed=drv_set_spd, host_accel_max=ah_max, state_batch=state_batch, ctrl_batch=ctrl_batch, curr_state_vec=curr_state_vec, Np=Np)

        # Assembling the lower bound, upper bound, and coefficient (A) matrices for the system constraints
        lb = np.vstack((lb_input, lb_jerk_slack, lb_out))
        ub = np.vstack((ub_input, ub_jerk_slack, ub_out))
        A_ineq = np.vstack((A_input, A_jerk_slack, A_out))

        # creating the cost matrices (Hessian and such) to be used by the solver
        H, f = mpc.cost_matrices_create(state_batch=state_batch, ctrl_batch=ctrl_batch, curr_state_vec=curr_state_vec, Np=Np, q_vh=q_vh, q_ah=q_ah, q_dfoll_err=q_dfoll_err, q_vrel=q_vrel, r_delta_a_cmd=r_a_delta_cmd, rho_vh_max=rho_vh_max, rho_ah_max=rho_ah_max, rho_ah_min=rho_ah_min)

        # Calling the OSQP solver function with updated constraints, H, and f matrices
        delta_U_opt = osqp_utils.osqp_mpc_helper(N=Np, num_ctrl=1, H=H, f=f.flatten(), A_ineq=A_ineq, lb=lb.flatten(), ub=ub.flatten())

        # Computing the commanded/applied acceleration = delta_a_cmd + a_cmd_prev
        a_cmd = u_prev + delta_U_opt[:1]
        
        # Updating the persistent variable values to be used in next timestep
        self.delta_U_prev = delta_U_opt
        self.u_prev = a_cmd

        # Outputting the acceleration which is the control input to our system
        self.write("a_cmd", a_cmd)
        self.write("seen_dist", derr)

# Death() will be called once at diagram execution shutdown
    def Death(self):
        print("Passing through Death()")
