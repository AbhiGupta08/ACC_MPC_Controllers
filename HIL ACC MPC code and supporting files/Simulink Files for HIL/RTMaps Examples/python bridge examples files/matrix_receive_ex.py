import rtmaps.core as rt
import rtmaps.types
from rtmaps.base_component import BaseComponent  # base class
from rtmaps.types import Matrix  # import this so can output matrices directly without RTMaps converting to long array
import numpy as np
from scipy.linalg import block_diag # to create block diagonal matrices

# Python class that will be called from RTMaps.
class rtmaps_python(BaseComponent):
    
    # Constructor has to call the BaseComponent parent class
    def __init__(self):
        BaseComponent.__init__(self)  # call base class constructor

    # Dynamic is called frequently: When loading the diagram; When connecting or disconnecting a wire; Here you create your inputs, outputs and properties
    def Dynamic(self):
        # Inputs to this component are output matrix dimensions
        self.add_input("mat_in", rtmaps.types.MATRIX)

# Birth() will be called once at diagram execution startup; can initialize variables here that would persist (keep their last value) between calls to Core() 
    def Birth(self):
        print("Passing through Birth()")

# Core() is called every time you have a new inputs available, depending on your chosen reading policy
    def Core(self):
        # Extracting matrix from input
        mat_in = self.inputs["mat_in"].ioelt.data.matrix_data

        print("matrix received", mat_in)

# Death() will be called once at diagram execution shutdown
    def Death(self):
        print("Passing through Death()")
