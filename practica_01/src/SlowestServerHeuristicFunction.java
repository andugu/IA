package src;

import aima.search.framework.HeuristicFunction;

public class SlowestServerHeuristicFunction implements HeuristicFunction {

    @Override
    public double getHeuristicValue(Object state) {
        State currentState = (State) state;
        return currentState.getMaxTransmissionTime();
    }
}
