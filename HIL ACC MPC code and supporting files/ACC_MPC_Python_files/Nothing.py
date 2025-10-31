# ---------------- TEMPLATE ---------------------------------------
# This is a template to help you start writing PythonBridge code  -
# -----------------------------------------------------------------

import rtmaps.core as rt
import rtmaps.types
from rtmaps.base_component import BaseComponent  # base class

# Python class that will be called from RTMaps.
class rtmaps_python(BaseComponent):
    
    # Constructor has to call the BaseComponent parent class
    def __init__(self):
        BaseComponent.__init__(self)  # call base class constructor

    # Dynamic is called frequently:
    # - When loading the diagram
    # - When connecting or disconnecting a wire
    # Here you create your inputs, outputs and properties
    def Dynamic(self):
        # Adding an input called "in" of ANY type
        self.add_input("in", rtmaps.types.ANY)  # define an input

        # Define the output. The type is set to AUTO which means that the output will be typed automatically.
        # You don’t need to set the buffer_size, in that case it will be set automatically.
        self.add_output("out", rtmaps.types.AUTO)
        
        self.add_property("sumth", 3)
        self.add_output("uhmm", rtmaps.types.AUTO)
        
# Birth() will be called once at diagram execution startup
    def Birth(self):
        print("Passing through Birth()")

# Core() is called every time you have a new inputs available, depending on your chosen reading policy
    def Core(self):
        # Just copy the input to the output here
        out = self.inputs["in"].ioelt
        self.write("out", out)
        moreout = self.get_property("sumth")*out.data
        self.write("uhmm", moreout)

# Death() will be called once at diagram execution shutdown
    def Death(self):
        print("Passing through Death()")
