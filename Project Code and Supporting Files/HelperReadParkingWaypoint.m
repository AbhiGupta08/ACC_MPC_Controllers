classdef HelperReadParkingWaypoint < matlab.System
    methods(Access = protected)
        function waypoint = stepImpl(~, ~, PathAction)
            if ~isempty(PathAction) && PathAction.PathTarget.NumPoints >= 1
                waypoint = PathAction.PathTarget.Path(1,1:2); % Extract first [x y]
            else
                waypoint = [NaN NaN];
            end
        end

        function interface = getInterfaceImpl(~)
            import matlab.system.interface.*
            interface = [Input("in1", Message), ...  % ActorRuntime
                         Input("in2", Message), ...  % PathAction
                         Output("out1", Data)];
        end

        function out = getOutputSizeImpl(~), out = [1 2]; end
        function out = getOutputDataTypeImpl(~), out = "double"; end
        function out = isOutputFixedSizeImpl(~), out = true; end
        function out = isOutputComplexImpl(~), out = false; end
    end
end
