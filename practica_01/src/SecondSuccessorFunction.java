package src;

import aima.search.framework.Successor;
import aima.search.framework.SuccessorFunction;

import java.util.ArrayList;
import java.util.List;

public class SecondSuccessorFunction implements  SuccessorFunction{

    @Override
    public List getSuccessors(Object state) {
        ArrayList retVal = new ArrayList();
        State currentState = (State)state;
        var successors = currentState.swap();
        for(State s : successors){
            retVal.add(new Successor("Swaped request form server", s));
        }
        return retVal;
    }
}
