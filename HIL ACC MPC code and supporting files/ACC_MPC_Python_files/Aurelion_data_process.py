import rtmaps.core as rt
import rtmaps.types
from rtmaps.base_component import BaseComponent  # base class
import numpy as np
import math

import importlib # Use this code library to reload this code at bridge component startup in case changes made to code

# Python class that will be called from RTMaps.
class rtmaps_python(BaseComponent):
    
    # Constructor has to call the BaseComponent parent class
    def __init__(self):
        BaseComponent.__init__(self)  # call base class constructor

    def Dynamic(self):
        self.add_input("relative_dist_1", rtmaps.types.FLOAT64) # distance feedback from Aurelion of immediate lead in procession; m
        self.add_input("relative_vel_1", rtmaps.types.FLOAT64) # relative velocity feedback for immediate lead in Aurelion; m/s
        self.add_input("sim_ego_vel", rtmaps.types.FLOAT64) 
        self.add_input("sim_state", rtmaps.types.FLOAT64) # state of simulation environment (0 = off; 1 = active)
        self.add_input("sim_mode", rtmaps.types.FLOAT64) # mode is always 2 == speed feedback; indicates whether in speed or accel feedback mode
        # self.add_input("dyno_mode_request", rtmaps.types.FLOAT64)
        # self.add_input("sim_time", rtmaps.types.FLOAT64)
        # self.add_input("accel_1", rtmaps.types.FLOAT64)
        # self.add_input("rel_dist_2", rtmaps.types.FLOAT64)
        # self.add_input("rel_vel_2", rtmaps.types.FLOAT64)
        # self.add_input("accel_2", rtmaps.types.FLOAT64)
        # self.add_input("rel_dist_3", rtmaps.types.FLOAT64)
        # self.add_input("rel_speed_3", rtmaps.types.FLOAT64)
        # self.add_input("accel_3", rtmaps.types.FLOAT64)
        # self.add_input("time_next_phase_1", rtmaps.types.FLOAT64)
        # self.add_input("intsctn_dist_1", rtmaps.types.FLOAT64)
        # self.add_input("curr_phase_1", rtmaps.types.FLOAT64)
        # self.add_input("time_next_phase_2", rtmaps.types.FLOAT64)
        # self.add_input("intsctn_dist_2", rtmaps.types.FLOAT64)
        # self.add_input("curr_phase_2", rtmaps.types.FLOAT64)
        # self.add_input("time_next_phase_3", rtmaps.types.FLOAT64)
        # self.add_input("intsctn_dist_3", rtmaps.types.FLOAT64)
        # self.add_input("curr_phase_3", rtmaps.types.FLOAT64)

        self.add_output("closest_follow_dist", rtmaps.types.FLOAT64) # following distance from closest lead vehicle; m
        self.add_output("rel_vel_closest", rtmaps.types.FLOAT64) # relative velocity from closest lead vehicle; m/s 
        self.add_output("sim_ego_vel_out", rtmaps.types.FLOAT64)
        self.add_output("sim_state_out", rtmaps.types.FLOAT64)
        
# Birth() will be called once at diagram execution startup
    def Birth(self):
        # importlib.reload()

        print("Passing through Birth()")

# Core() is called every time you have a new inputs available, depending on your chosen reading policy
    def Core(self):
        # Extracting inputs
        rel_dist_1 = self.inputs["relative_dist_1"].ioelt.data
        rel_vel_1 = self.inputs["relative_vel_1"].ioelt.data # host velocity in m/s
        ego_vel_sim = self.inputs["sim_ego_vel"].ioelt.data
        sim_state = self.inputs["sim_state"].ioelt.data
        sim_mode = self.inputs["sim_mode"].ioelt.data

        if sim_state == 0.0:
            self.write("closest_follow_dist", 0.0)
            self.write("rel_vel_closest", 0.0)
            self.write("sim_ego_vel_out", 0.0)
            self.write("sim_state_out", sim_state)
        else:
            self.write("closest_follow_dist", rel_dist_1)
            self.write("rel_vel_closest", rel_vel_1)
            self.write("sim_ego_vel_out", ego_vel_sim)
            self.write("sim_state_out", sim_state)

        
# Death() will be called once at diagram execution shutdown
    def Death(self):
        print("Passing through Death()")
