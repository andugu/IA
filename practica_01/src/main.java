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
import java.util.Random;

public class main {

    private enum Algorithm{
        HillClimbing,
        SimulatedAnnealing
    }

    public static void RunExperiment(int seed, int nServers, int nRepetitions, int nUsers , int nRequests, Algorithm algType, String initSt, String sucFunc, String heur) throws Exception {
        int rounds = 1000;
        long elapsedTime = 0;
        long initialMaxTransmissionTime = 0;
        long finalMaxTransmissionTime = 0;
        int steps = 100000;
        int stiter = 50;
        int k = 50;
        double lambda = 0.005;
        Random rand = new Random();
        rand.setSeed(seed);
        for(int i = 0; i < rounds; ++i){
            System.out.println("Current round: " + i);
            // GENERATE PROBLEM DATA
            Servers servers = new Servers(nServers, nRepetitions, seed);
            Requests requests = new Requests(nUsers, nRequests, seed);

            // CREATE INITIAL STATE
            State initialState = new State(seed);
            if (initSt.equals("state1"))
                initialState.initialState1(servers, requests);
            else
                initialState.initialState2(servers, requests);
            initialState.printState();

            // SET NO GOAL
            DummyGoalTest goal = new DummyGoalTest();

            // CREATE OPERATORS
            SuccessorFunction successorFunction;
            switch (sucFunc) {
                case "op1":
                    successorFunction = new FirstSuccessorFunction();
                    break;
                case "op2":
                    successorFunction = new SecondSuccessorFunction();
                    break;
                case "op4":
                    successorFunction = new AndSuccessorFunction();
                    break;
                default:
                    successorFunction = new ThirdSuccessorFunction();

            }

            // SELECT HEURISTIC
            HeuristicFunction heuristic;
            if (heur.equals("best"))
                heuristic = new FirstHeuristicFunction();
            else
                heuristic = new SlowestServerHeuristicFunction();

            // ALGORITHM
            // steps = numero de temperaturs
            // stiter = numero de iteraciones
            // k = temp inicial
            // lamb = decremento

            Search algorithm = null;
            if(algType == Algorithm.HillClimbing){
                algorithm = new HillClimbingSearch();
            }
            else if(algType == Algorithm.SimulatedAnnealing){
                algorithm = new SimulatedAnnealingSearch(steps, stiter, k, lambda); // <= falta pasar parametros
            }

            // CREATE PROBLEM
            Problem p = new Problem(initialState, successorFunction, goal, heuristic);

            // Instantiate the SearchAgent object
            long initialTime = java.lang.System.currentTimeMillis();
            SearchAgent agent = new SearchAgent(p, algorithm);
            long finalTime = java.lang.System.currentTimeMillis();

            //System.out.println("STEPS");
            // printActions(agent.getActions());
            //System.out.println("");

            elapsedTime += finalTime-initialTime;
            State finalState = (State)algorithm.getGoalState();
            elapsedTime += finalTime-initialTime;
            initialMaxTransmissionTime += initialState.getMaxTransmissionTime();
            finalMaxTransmissionTime += finalState.getMaxTransmissionTime();

            // update seed
            seed = rand.nextInt();
        }
        elapsedTime /= rounds;
        initialMaxTransmissionTime /= rounds;
        finalMaxTransmissionTime /= rounds;
        System.out.println("Steps = " + steps);
        System.out.println("stiter = " + stiter);
        System.out.println("k = " + k);
        System.out.println("lambda = " + lambda);
        System.out.println("Elapsed time: " + elapsedTime);
        System.out.println("InitialMaxTransmissionTime: " + initialMaxTransmissionTime);
        System.out.println("FinalMaxTransmissionTime: " + finalMaxTransmissionTime);
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
        
        if (args.length != 9 || args[0].equals("-h")){
            System.out.println("Usage: java -jar practica_01.jar seed nServers nRepetitions nUsers nRequests algorithm initialState successorFunction heuristic\n");
            System.out.println("seed, nServers, nRepetitions, nUsers, nRequests are int numbers\n");
            System.out.println("algorithm:\n");
            System.out.println("    hc --> HillClimbing\n");
            System.out.println("    sa --> SimulatedAnnealing\n");
            System.out.println("initialState:\n");
            System.out.println("    state1 --> assign each request to the server with less delay\n");
            System.out.println("    state2  --> for random assignation\n");
            System.out.println("successorFunction (operator)\n");
            System.out.println("    op1    --> moveMaxFile: moves slowest file from lowest server\n");
            System.out.println("    op2    --> moveRandomFile: a random server is selected, and the file at its peak is moved to all others\n");
            System.out.println("    op3    --> combination: op1 + op2\n");
            System.out.println("    op4    --> combination: op1 intersection op2\n");
            System.out.println("heuristic:\n");
            System.out.println("    best          --> take into account maxTransmissionTime & std from all servers\n");
            System.out.println("    slowestServer --> only checks MaxTransmissionTime\n");
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

        if (!args[6].equals("state1") && !args[6].equals("state2")){
            System.out.println(args[6]+" isn't a valid initialState");
            System.exit(-1);
        }

        if (!args[7].equals("op1") && !args[7].equals("op2") && !args[7].equals("op3")&& !args[7].equals("op4")){
            System.out.println(args[7]+" isn't a valid successorFunction");
            System.exit(-1);
        }

        if (!args[8].equals("best") && !args[8].equals("slowestServer")){
            System.out.println(args[8]+" isn't a valid heuristic");
            System.exit(-1);
        }

        try{
            RunExperiment(Integer.parseInt(args[0]), Integer.parseInt(args[1]),
                          Integer.parseInt(args[2]), Integer.parseInt(args[3]),
                          Integer.parseInt(args[4]), type, args[6], args[7], args[8]);

        }
        catch (Exception e){
            e.printStackTrace();
        }
    }
}
