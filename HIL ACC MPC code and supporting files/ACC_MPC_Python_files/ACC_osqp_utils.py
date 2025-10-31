# import numpy as np
# import osqp
# from scipy import sparse

# # ---------- persistent-like globals (module level) ----------
# _solver = None
# _setup_done = False
# _nvar = None
# _ncon = None


# def osqp_mpc_helper(N, num_ctrl, H, f, A_ineq, lb, ub):
#     """
#     Equivalent to MATLAB OSQP_MPC_helper.

#     z = [Δu; s_vh; s_ah+; s_ah-]
#     Returns the first N*num_ctrl elements (Δu).

#     Parameters
#     ----------
#     N : int
#         Prediction horizon.
#     num_ctrl : int
#         Number of control inputs.
#     H : (n,n) ndarray or sparse
#         Hessian of the cost (must be symmetric PSD).
#     f : (n,) ndarray
#         Linear cost vector.
#     A_ineq : (m,n) ndarray or sparse
#         Constraint matrix.
#     lb, ub : (m,) ndarray
#         Lower/upper bounds.

#     Returns
#     -------
#     delta_Uopt : ndarray
#         Optimal control increments Δu (length N*num_ctrl).
#     """

#     global _solver, _setup_done, _nvar, _ncon

#     # ----------- basic validity checks -----------
#     if np.any(~np.isfinite(lb)) or np.any(~np.isfinite(ub)):
#         raise ValueError("lb/ub contain non-finite values.")
#     bad = np.where(lb > ub)[0]
#     if bad.size:
#         i = bad[0]
#         raise ValueError(f"Invalid bounds row {i}: l={lb[i]}, u={ub[i]}")

#     # Ensure sparse CSC format
#     H = sparse.csc_matrix(H)
#     A_ineq = sparse.csc_matrix(A_ineq)

#     nvar, ncon = H.shape[0], A_ineq.shape[0]
#     f = np.asarray(f).reshape(-1)
#     lb = np.asarray(lb).reshape(-1)
#     ub = np.asarray(ub).reshape(-1)

#     # ----------- first-time setup -----------
#     if not _setup_done:
#         _nvar, _ncon = nvar, ncon
#         _solver = osqp.OSQP()
#         _solver.setup(
#             P=H, q=f, A=A_ineq, l=lb, u=ub,
#             warm_start=True, verbose=False,
#             eps_abs=1e-3, eps_rel=1e-3, max_iter=4000
#         )
#         _setup_done = True

#     # ----------- update numerics only -----------
#     else:
#         # rebuild if sizes change
#         if nvar != _nvar or ncon != _ncon:
#             _setup_done = False
#             return osqp_mpc_helper(N, num_ctrl, H, f, A_ineq, lb, ub)

#         # single unified update call
#         _solver.update(q=f, l=lb, u=ub, Px=H.data, Ax=A_ineq.data)

#     # ----------- solve -----------
#     res = _solver.solve()
#     if res.info.status_val not in (1, 2):   # 1 = solved, 2 = solved inaccurate
#         raise RuntimeError(f"OSQP failed: {res.info.status}")

#     z = np.array(res.x, dtype=float)
#     return z[:N * num_ctrl]   # Δu block only

import numpy as np
import osqp
from scipy import sparse

# ---------- persistent-like globals (module level) ----------
_solver = None
_setup_done = False
_maskP = None
_maskA = None
_nvar = None
_ncon = None


def osqp_mpc_helper(N, num_ctrl, H, f, A_ineq, lb, ub):
    """
    Equivalent to MATLAB OSQP_MPC_helper
    (long-term fix: fixed sparsity pattern for H and A).
    """
    global _solver, _setup_done, _maskP, _maskA, _nvar, _ncon

    # ----- 1. sanity checks -----
    if np.any(~np.isfinite(lb)) or np.any(~np.isfinite(ub)):
        raise ValueError("lb/ub contain non-finite values.")
    bad = np.where(lb > ub)[0]
    if bad.size:
        i = bad[0]
        raise ValueError(f"Invalid bounds row {i}: l={lb[i]}, u={ub[i]}")

    # Convert to sparse CSC (OSQP requirement)
    H = sparse.csc_matrix(H)
    A_ineq = sparse.csc_matrix(A_ineq)
    nvar, ncon = H.shape[0], A_ineq.shape[0]
    f = np.asarray(f).reshape(-1)
    lb = np.asarray(lb).reshape(-1)
    ub = np.asarray(ub).reshape(-1)

    # # Printing Norm values for 
    # print("‖H‖ =", np.linalg.norm(H.data, np.inf),
    #     "‖A‖ =", np.linalg.norm(A_ineq.data, np.inf),
    #     "‖f‖ =", np.linalg.norm(f, np.inf))

    # ==============================================================
    #  First-time setup: capture sparsity pattern
    # ==============================================================
    if not _setup_done:
        _nvar, _ncon = nvar, ncon

        # Store binary masks of nonzero structure
        _maskP = H.copy()
        _maskP.data[:] = 1.0
        _maskA = A_ineq.copy()
        _maskA.data[:] = 1.0

        # Numerical placeholders with same structure
        P0 = sparse.triu(H)     # upper triangle for symmetric P
        A0 = A_ineq.copy()

        _solver = osqp.OSQP()
        _solver.setup(
            P=P0, q=f, A=A0, l=lb, u=ub,
            warm_start=True, verbose=False,
            eps_abs=1e-3, eps_rel=1e-3, max_iter=4000
        )
        _setup_done = True
        res = _solver.solve()
        z = res.x

    # ==============================================================
    #  Subsequent iterations: numeric updates only
    # ==============================================================
    else:
        # Sanity: dimension consistency
        if nvar != _nvar or ncon != _ncon:
            raise ValueError("H/A dimensions changed since setup — invalid.")

        # Apply stored sparsity masks to force zeros
        H_masked = H.multiply(_maskP)     # same nonzero pattern as initial
        A_masked = A_ineq.multiply(_maskA)

        # Ensure upper triangle numeric values only
        H_masked = sparse.triu(H_masked)

        # Single unified update (modern OSQP)
        _solver.update(q=f, l=lb, u=ub, Px=H_masked.data, Ax=A_masked.data)

        res = _solver.solve()
        z = res.x
        # print("OSQP status:", res.info.status)

    # Handle solver status
    if res.info.status_val not in (1, 2):
        raise RuntimeError(f"OSQP failed: {res.info.status}")

    # Return Δu block only
    return np.array(z[:N * num_ctrl], dtype=float)
