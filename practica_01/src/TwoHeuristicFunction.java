package src;

import aima.search.framework.HeuristicFunction;

public class TwoHeuristicFunction implements HeuristicFunction {

    @Override
    public double getHeuristicValue(Object state) {
        State currentState = (State) state;
        return -1; // NO IMPLEMENTADA YA QUE NO SE SI INCLUIR
        // EL BALANCE EN ESTE CRITERIO O NO!?!!?
    }
}
