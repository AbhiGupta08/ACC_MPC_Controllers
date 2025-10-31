# This program takes inputs from the batch matrix creation block and then processes them to create the constraint matrices for OSQP solver for the MPC problem
# Includes constraints on 
###control input: applied acceleration
###outputs: host velocity and acceleration
###control input deviation: delta_applied acceleration (jerk constraint)
# Slack variables are also present for maximum host velocity, maximum and minimum host accelerations

# Inputs to this python bridge component are: state batch matrix, control batch matrix, delta_U_bar(k-1) (full optimized control vector from before), vh(k), ah(k), derr(k), vrel(k), accel_app(k-1) 

import rtmaps.types
from rtmaps.types import Matrix
from rtmaps.base_component import BaseComponent  # base class
import numpy as np

# Python class that will be called from RTMaps.
class rtmaps_python(BaseComponent):
    
    # Constructor has to call the BaseComponent parent class
    def __init__(self):
        BaseComponent.__init__(self)  # call base class constructor

    # Dynamic is called frequently:
    def Dynamic(self):
        # Adding system properties/parameters here for MPC
        self.add_property("sample_time", 0.05) # chosen MPC sample time; s
        self.add_property("prediction_horizon", 20) # chosen MPC prediction horizon and control horizon

        # Creating system properties for constraint values to be applied to the system
        self.add_property("Host_Veloc_max", 25.0) ##### Constraint on v_host; m/s (same as driver set speed; may be turned into input to system instead) #####
        self.add_property("Applied_Accel_max", 3.5) # Constraint on a_app; m/s^2
        self.add_property("Host_Accel_max", 2.5) # Constraint on a_host; m/s^2
        self.add_property("Jerk_max", 5) # Constraint on delta_a_app/Ts; m/s^3
        
        # Getting augmented system matrices from previous block
        self.add_input("state_batch", rtmaps.types.MATRIX)
        self.add_input("ctrl_batch", rtmaps.types.MATRIX)
        # self.add_input("host_veloc", rtmaps.types.FLOAT64)
        # self.add_input("host_accel", rtmaps.types.FLOAT64)
        # self.add_input("follow_dist_err", rtmaps.types.FLOAT64)
        # self.add_input("rltve_veloc", rtmaps.types.FLOAT64)
        # self.add_input("applied_accel_prev", rtmaps.types.FLOAT64)
        # self.add_input("delta_U_bar_prev", rtmaps.types.MATRIX) # This is the full optimized control vector from the previous time step

        # Outputting the constraint matrices for the solver in the form lb < A_cnstrnt * delta_U_bar < ub 
        self.add_output("A_cnstr_mat", rtmaps.types.MATRIX) # equivalent to F in textbook notation
        self.add_output("lower_bnd_mat", rtmaps.types.MATRIX) # equivalent to PHI in textbook notati
        self.add_output("uppr_bnd_mat", rtmaps.types.MATRIX) # equivalent to PHI in textbook notati

# Birth() will be called once at diagram execution startup
    def Birth(self):
        print("Passing through Birth()")

# Core() is called every time you have a new inputs available, depending on your chosen reading policy
    def Core(self):
        # Accessing bridge component inputs to extract augmented system matrices
        state_batch = self.inputs["state_batch"].ioelt
        ctrl_batch = self.inputs["ctrl_batch"].ioelt

        # # Extracting state feedback from the inputs to compute constraints
        # vh = self.inputs["host_veloc"].ioelt.data
        # ah = self.inputs["host_accel"].ioelt.data
        # derr = self.inputs["follow_dist_error"].ioelt.data
        # vrel = self.inputs["rltve_veloc"].ioelt.data
        # acc_app_prev = self.inputs["applied_accel_prev"].ioelt.data
        # delta_U_bar_prev = self.inputs["delta_U_bar_prev"].ioelt.data.matrix_data
        
        # Extracting component properties to get MPC parameters for batch matrix creation
        Ts = self.get_property("sample_time")
        Np = self.get_property("prediction_horizon")

        # print("state_batch",state_batch.data.matrix_data.shape)
        # print("ctrl_batch",ctrl_batch.data.matrix_data.shape)
        
        # # Writing the MPC batch system MATRIX objects to component outputs
        # self.write("state_batch", state_batch)
        # self.write("ctrl_batch", ctrl_batch)

# Death() will be called once at diagram execution shutdown
    def Death(self):
        print("Passing through Death()")
