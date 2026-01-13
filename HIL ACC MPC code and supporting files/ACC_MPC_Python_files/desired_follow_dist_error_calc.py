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
        self.add_input("desired_dist_setting", rtmaps.types.FLOAT64) # driver's setting for how far they want desired distance; Discrete options are 1.5, 2, 3: larger numbers means get closer to car in front
        self.add_input("host_velocity", rtmaps.types.FLOAT64) # host/ego vehicle's longitudinal velocity feedback; in m/s
        self.add_input("actual_following_dist", rtmaps.types.FLOAT64) # this is the actual following distance from lead vehicle value reported by radar/simulation

        # For AURELION co-simulation
        self.add_input("sim_state_in", rtmaps.types.FLOAT64) # simulation state 0 = INACTIVE; 1 = ACTIVE

        self.add_output("follow_dist_error", rtmaps.types.FLOAT64) # the following distance error calculated
        self.add_output("desired_follow_dist", rtmaps.types.FLOAT64) # the desired following distance being determined
        
# Birth() will be called once at diagram execution startup
    def Birth(self):
        # importlib.reload()

        print("Passing through Birth()")

# Core() is called every time you have a new inputs available, depending on your chosen reading policy
    def Core(self):
        # Extracting inputs
        des_dist_const = self.inputs["desired_dist_setting"].ioelt.data
        vh = self.inputs["host_velocity"].ioelt.data # host velocity in m/s
        act_foll_dist = self.inputs["actual_following_dist"].ioelt.data

        # need for AURELION
        sim_state = self.inputs["sim_state_in"].ioelt.data # simulation state 0 = INACTIVE; 1 = ACTIVE
        
        vh_mph = float(vh)*2.237 # converting ego/host speed from meters per sec. to miles per hour

        # Initializing the values for the following distance bounds (in meters) based on a 0 mph vehicle speed (at standstill)
        CFD = 8.0 # Closest follow distance; m
        FFD = 100.0 # Farthest follow distance; m

        if vh_mph > 0.0 and vh_mph <= 20.0:
            CFD = 2.8*math.pow(vh_mph, 0.45) + 8.0
            FFD = 100.0 - 0.2*math.pow(20 - vh_mph, 2)
        elif vh_mph > 20.0:
            CFD = 2.8*math.pow(vh_mph, 0.45) + 8.0
            FFD = 100.0
        
        # desired following distance which is an average between bounds depending on des_dist_const value from 1.5 to 3: eg. 3 would be a desired dist. that's a third of the distance from the CFD
        des_foll_dist = ((float(des_dist_const)-1)*CFD + FFD)/float(des_dist_const)
        foll_dist_error_calc = float(des_foll_dist) - float(act_foll_dist)
        
        if sim_state == 0.0:
            self.write("follow_dist_error", 0.0)
        else:
            self.write("follow_dist_error", foll_dist_error_calc)

        self.write("desired_follow_dist", des_foll_dist)
        
# Death() will be called once at diagram execution shutdown
    def Death(self):
        print("Passing through Death()")
