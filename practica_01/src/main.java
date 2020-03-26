package src;

import IA.DistFS.Requests;
import IA.DistFS.Servers;
import aima.search.framework.Problem;
import aima.search.framework.Search;
import aima.search.framework.SearchAgent;
import aima.search.informed.HillClimbingSearch;
import aima.search.informed.SimulatedAnnealingSearch;
import aima.search.framework.SuccessorFunction;
import aima.search.framework.HeuristicFunction;

import java.util.Iterator;
import java.util.List;
import java.util.Properties;

public class main {

    private enum Algorithm{
        HillClimbing,
        SimulatedAnnealing
    }

    public static void RunExperiment(int seed, int nServers, int nRepetitions, int nUsers , int nRequests, Algorithm algType, String initSt, String sucFunc, String heur) throws Exception {

        // GENERATE PROBLEM DATA
        Servers servers = new Servers(nServers, nRepetitions, seed);
        Requests requests = new Requests(nUsers, nRequests, seed);

        // CREATE INITIAL STATE
        State initialState = new State();
        if (initSt.equals("fastest"))
            initialState.initialState1(servers, requests);
        else
            initialState.initialState2(servers, requests);
        initialState.printState();

        // SET NO GOAL
        DummyGoalTest goal = new DummyGoalTest();

        // CREATE OPERATORS
        SuccessorFunction successorFunction;
        if (sucFunc.equals("moveSlowest"))
            successorFunction = new FirstSuccessorFunction();
        else
            successorFunction = new SecondSuccessorFunction();

        // SELECT HEURISTIC
        HeuristicFunction heuristic;
        if (heur.equals("best"))
            heuristic = new FirstHeuristicFunction();
        else
            heuristic = new SlowestServerHeuristicFunction();

        // ALGORITHM
        Search algorithm = null;
        if(algType == Algorithm.HillClimbing){
            System.out.println("Starting Hill Climbing...");
            algorithm = new HillClimbingSearch();
        }
        else if(algType == Algorithm.SimulatedAnnealing){
            System.out.println("Starting Simulated Annealing...");
            algorithm = new SimulatedAnnealingSearch(); // <= falta pasar parametros
        }

        // CREATE PROBLEM
        Problem p = new Problem(initialState, successorFunction, goal, heuristic);

        // Instantiate the SearchAgent object
        long initialTime = java.lang.System.currentTimeMillis();
        SearchAgent agent = new SearchAgent(p, algorithm);
        long finalTime = java.lang.System.currentTimeMillis();

        //System.out.println("STEPS");
        //printActions(agent.getActions());
        //System.out.println("");

        printInstrumentation(agent.getInstrumentation());
        System.out.println("");

        System.out.println("Time: " + (finalTime-initialTime) + "ms");
        System.out.println("");

        State finalState = (State)algorithm.getGoalState();

        System.out.println("InitialState:");
        System.out.println(initialState.printState());
        System.out.println("");

        System.out.println("FinalState:");
        System.out.println(finalState.printState());
        System.out.println("");
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

        System.out.println("");
        
        if (args.length != 9){
            System.out.println("Usage: java -jar practica_01.jar seed nServers nRepetitions nUsers nRequests algorithm initialState successorFunction heuristic");
            System.out.println("");
            System.out.println("seed, nServers, nRepetitions, nUsers, nRequests are int numbers");
            System.out.println("");
            System.out.println("algorithm:");
            System.out.println("    hc --> HillClimbing");
            System.out.println("    sa --> SimulatedAnnealing");
            System.out.println("");
            System.out.println("initialState:");
            System.out.println("    fastest --> assign each request to the server with less delay");
            System.out.println("    random  --> for random assignation");
            System.out.println("");
            System.out.println("successorFunction (operator)");
            System.out.println("    moveSlowest --> moves slowest file from lowest server");
            System.out.println("    swap        --> //TODO");
            System.out.println("");
            System.out.println("heuristic:");
            System.out.println("    best    --> take into account maxTransmissionTime & std from all servers");
            System.out.println("    slowest --> only checks MaxTransmissionTime");
            System.out.println("");
            System.exit(-1);
        }

        Algorithm type = null;
        if (args[5].equals("hc"))
            type = Algorithm.HillClimbing;
        else if (args[5].equals("sa"))
            type = Algorithm.SimulatedAnnealing;
        else {
            System.out.println(args[5]+" isn't a valid algorithm");
            System.exit(-1);
        }

        if (!args[6].equals("fastest") && !args[6].equals("random")){
            System.out.println(args[6]+" isn't a valid initialState");
            System.exit(-1);
        }

        if (!args[7].equals("moveSlowest") && !args[7].equals("swap")){
            System.out.println(args[7]+" isn't a valid successorFunction");
            System.exit(-1);
        }

        if (!args[8].equals("best") && !args[8].equals("slowest")){
            System.out.println(args[8]+" isn't a valid heuristic");
            System.exit(-1);
        }

        try{
            RunExperiment(Integer.parseInt(args[0]), Integer.parseInt(args[1]), Integer.parseInt(args[2]), Integer.parseInt(args[3]), Integer.parseInt(args[4]), type, args[6], args[7], args[8]);
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }
}
