package src;

import IA.DistFS.Requests;
import IA.DistFS.Servers;
import aima.search.framework.GoalTest;
import aima.search.framework.Problem;
import aima.search.framework.Search;
import aima.search.framework.SearchAgent;
import aima.search.informed.HillClimbingSearch;
import aima.search.informed.SimulatedAnnealingSearch;

import java.util.Iterator;
import java.util.List;
import java.util.Properties;

public class main {

    private enum Algorithm{
        HillClimbing,
        SimulatedAnnealing
    }

    public static void RunExperiment(int seed, int nServers, int nRepetitions, int nUsers , int nRequests, Algorithm algType) throws Exception {

        // GENERATE PROBLEM DATA
        Servers servers = new Servers(nServers, nRepetitions, seed);
        Requests requests = new Requests(nUsers, nRequests, seed);

        // CREATE INITIAL STATE
        State initialState = new State();
        initialState.initialState1(servers, requests);
        initialState.printState();
        // CREATE PROBLEM
        DummyGoalTest goal = new DummyGoalTest();
        Search algorithm = null;
        FirstSuccessorFunction successorFunction = new FirstSuccessorFunction();
        FirstHeuristicFunction heuristic = new FirstHeuristicFunction();

        if(algType == Algorithm.HillClimbing){
            System.out.println("Starting Hill Climbing...");
            algorithm = new HillClimbingSearch();
        }
        else if(algType == Algorithm.SimulatedAnnealing){
            System.out.println("Starting Simulated Annealing...");
            algorithm = new SimulatedAnnealingSearch(); // <= falta pasar parametros
        }
        Problem p = new Problem(initialState, successorFunction, goal, heuristic);

        // Instantiate the SearchAgent object
        long initialTime = java.lang.System.currentTimeMillis();
        SearchAgent agent = new SearchAgent(p, algorithm);
        long finalTime = java.lang.System.currentTimeMillis();
        System.out.println("STEPS");
        printActions(agent.getActions());
        printInstrumentation(agent.getInstrumentation());
        System.out.println("Time: " + (finalTime-initialTime) + "ms");
        State finalState = (State)algorithm.getGoalState();
        System.out.println("InitialState");
        System.out.println(initialState.printState());
        System.out.println("FinalState");
        System.out.println(finalState.printState());



    }


    //  PRINT FUNCTIONS (SOURCE = PDF IA)
    private static void printInstrumentation(Properties properties) {
        Iterator keys = properties.keySet().iterator();
        while (keys.hasNext()) {
            String key = (String) keys.next();
            String property = properties.getProperty(key);
            System.out.println(key + " : " + property);
        }

    }

    private static void printActions(List actions) {
        for (int i = 0; i < actions.size(); i++) {
            String action = (String) actions.get(i);
            System.out.println(action);
        }
    }


    public static void main(String[] args) {
        // DEFINE EXPERIMENT PARAMETERS
        int seed = 67646574;
        int nServers = 5;
        int nRepetitions = 2; // < nServers
        int nUsers = 50;
        int nRequests = 15;
        Algorithm type = Algorithm.HillClimbing;

        try{
            RunExperiment(seed, nServers, nRepetitions, nUsers, nRequests, type);
        }
        catch (Exception e){
            e.printStackTrace();
        }

    }
}
