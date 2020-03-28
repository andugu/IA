package src;

import aima.search.framework.Successor;
import aima.search.framework.SuccessorFunction;

import java.util.ArrayList;
import java.util.List;

public class AndSuccessorFunction implements SuccessorFunction {
    @Override
    public List getSuccessors(Object state) {
        ArrayList retVal = new ArrayList();
        State currentState = (State)state;
        // create successors
        var moveSuccessors = currentState.move();
        var swapSuccessors = currentState.swap();
        // add successors
        for(State s : moveSuccessors) retVal.add(new Successor("Move slowest file from lowest server", s));
        for(State s : swapSuccessors) retVal.add(new Successor("Swaped request form server", s));

        // trim successors
        retVal = createJointSet(retVal);

        return retVal;
    }


    // O(n log n) "and" implementation, pseudo merge sort
    private ArrayList createJointSet(ArrayList<Successor> nodes) {
        ArrayList<Successor> retVal = new ArrayList<Successor>();
        int left = 0;
        int right = retVal.size();
        recursiveJointSet(left, right, nodes, retVal);
        return retVal;
    }

    private void recursiveJointSet(int left, int right, ArrayList<Successor> nodes, ArrayList<Successor> retVal) {
        if(left < right) {
            int middle = left + (right-left)/2; // calculate middle with overflow avoidance
            recursiveJointSet(left, middle, nodes, retVal);
            recursiveJointSet(middle, right, nodes, retVal);
            merge(left, middle, right, nodes, retVal);
        }
    }

    private void merge(int left, int middle, int right, ArrayList<Successor> nodes, ArrayList<Successor> retVal) {
        int i = left;
        int j = middle;
        while(i < middle && j < right){
            int k = ((State)nodes.get(i).getState()).compare((State)nodes.get(j).getState());
            if(k == 0){
                Successor node = nodes.get(i);
                retVal.add(node);
                ++i;
            }
            else if(k == -1)++i; // increment left iterator
            else {
                Successor value = nodes.get(j);
                int index = j;
                while(index != i){
                    nodes.set(index, nodes.get(index - 1));
                    --index;
                }
                nodes.set(i, value);
                i++;
                middle++;
                j++;
            }; // increment right iterator
        }
    }


}
