package src;

import aima.search.framework.HeuristicFunction;

public class FirstHeuristicFunction implements HeuristicFunction {
    @Override
    public double getHeuristicValue(Object state) {
        State currentState = (State) state;
        float h1 = currentState.getMaxTransmissionTime();
        float h2 = currentState.getSumTransmissionTimes();
        float h3 = currentState.getSTD();
        return h1 + h2 + h3;
    }
}
