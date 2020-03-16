package src;
import aima.search.framework.GoalTest;

public class DummyGoalTest  implements  GoalTest{
    @Override
    public boolean isGoalState(Object state) {
        return false;
    }
}
