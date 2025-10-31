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
        # Adding system properties/parameters here
        self.add_property("multiplier", 2.4)

        # Inputs to this component are output matrix dimensions
        self.add_input("rows", rtmaps.types.INTEGER64)
        self.add_input("columns", rtmaps.types.INTEGER64)

        # Output from this component is a matrix
        self.add_output("mat_out", rtmaps.types.MATRIX)

# Birth() will be called once at diagram execution startup; can initialize variables here that would persist (keep their last value) between calls to Core() 
    def Birth(self):
        print("Passing through Birth()")

# Core() is called every time you have a new inputs available, depending on your chosen reading policy
    def Core(self):
        # Extracting dimensions from inputs
        rows = self.inputs["rows"].ioelt.data
        cols =  self.inputs["columns"].ioelt.data

        # Multiplier from property
        mult = self.get_property("multiplier")

        mat = mult * np.ones((rows,cols))

        # Creating empty Matrix objects to fill in with output data as RTMaps Python component expects an object of MATRIX type
        mat_out = Matrix(mat.shape[0], mat.shape[1])

        # Filling up the placeholder MATRIX objects initialized earlier to output data with
        mat_out.matrix_data[:] = mat

        # Writing the discrete system MATRIX objects to Python bridge component output variables
        self.write("mat_out", mat_out)

# Death() will be called once at diagram execution shutdown
    def Death(self):
        print("Passing through Death()")
