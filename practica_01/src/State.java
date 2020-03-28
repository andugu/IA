package src;

import IA.DistFS.Requests;
import IA.DistFS.Servers;

import java.util.*;

public class State{


	public State(int seed){
		randGenerator = new Random();
		randGenerator.setSeed(seed);
	}

	/**
	 * Copies a state into a new one
	 * */
	public State(State s){
		maxServerID = s.maxServerID;
		fillArrayList();
		for(int i = 0; i < nServers; ++i){
			dataStructure.set(i, new PriorityQueue<>(s.dataStructure.get(i)));
		}
		transmissionTimes = new ArrayList<>(s.transmissionTimes);
		maxTransmissionTime = s.maxTransmissionTime;
		sumTransmissionTimes = s.sumTransmissionTimes;
	}

	/************************************
	 * 			INITIAL STATES
	 *************************************/

	/**
	 * Initializes each request to the server with the fastest user-server transmission
	 * @param servers Contains informations about the servers
	 * @param requests Contains information about each request and user
	 * */
	public void initialState1(Servers servers, Requests requests){
		serversInfo = servers;
		nServers = servers.size();
		fillArrayList();
		for(int i = 0; i < requests.size(); ++i){
			int[] req = requests.getRequest(i); //[userID, fileID]
			File currentFile = new File(req[0], req[1]);
			Set<Integer> loc = servers.fileLocations(currentFile.getFileID());
			Iterator<Integer> it = loc.iterator();
			float min = 5001;
			int minServer = 0;
			while(it.hasNext()){
				Integer serverID = it.next();
				var current = servers.tranmissionTime(serverID, currentFile.getUserID());
				if(min > current){
					minServer = serverID;
					min = current;
				}
			}
			currentFile.setTransmissionTime(min);
			dataStructure.get(minServer).add(currentFile);
			transmissionTimes.set(minServer, transmissionTimes.get(minServer) + min);
		}
		calculateMaxAndSum();
	}

	/**
	 * Initializes each request to a random server
	 * @param servers Contains informations about the servers
	 * @param requests Contains information about each request and user
	 * */
	public void initialState2(Servers servers, Requests requests){
		serversInfo = servers;
		nServers = servers.size();
		fillArrayList();
		for(int i = 0; i < requests.size(); ++i){
			int[] req = requests.getRequest(i); //[userID, fileID]
			File currentFile = new File(req[0], req[1]);
			Set<Integer> loc = servers.fileLocations(currentFile.getFileID());
			Iterator<Integer> it = loc.iterator();

			int rand = randGenerator.nextInt(loc.size());
			int j = 0;
			while (j != rand) {
				j++;
				it.next();
			}
			Integer serverID = it.next();
			var time = servers.tranmissionTime(serverID, currentFile.getUserID());
			currentFile.setTransmissionTime(time);
			dataStructure.get(serverID).add(currentFile);
			transmissionTimes.set(serverID, transmissionTimes.get(serverID) + time);
		}
		calculateMaxAndSum();
	}

	/************************************
	 * 			OPERATORS
	 *************************************/

	public void moveMaxFile(int newLocation){
		// get max file
		File maxFile = dataStructure.get(maxServerID).poll();
		// update transmission times
		int userID = maxFile.getUserID();
		float newTransmissionTime = serversInfo.tranmissionTime(newLocation, userID);
		transmissionTimes.set(maxServerID, transmissionTimes.get(maxServerID) - maxFile.getTransmissionTime());
		transmissionTimes.set(newLocation, transmissionTimes.get(newLocation) + newTransmissionTime);
		maxFile.setTransmissionTime(newTransmissionTime);
		dataStructure.get(newLocation).add(maxFile);
		// recalculate variables
		calculateMaxAndSum();
	}

	public void moveRandomFile(int origin, int serverID){
		File top = dataStructure.get(origin).poll();
		int userID = top.getUserID();
		float newTransmissionTime = serversInfo.tranmissionTime(serverID, userID);
		transmissionTimes.set(origin, transmissionTimes.get(origin) - top.getTransmissionTime());
		transmissionTimes.set(serverID, transmissionTimes.get(serverID) + newTransmissionTime);
		top.setTransmissionTime(newTransmissionTime);
		dataStructure.get(serverID).add(top);
		calculateMaxAndSum();
	}

	/**
	 * This move operator selects the file with the lowest
	 * transmission time from the lowest server and moves it into n - 1
	 * servers (to the rest of the servers) this operator tries to minimize
	 * the transmission time and create a balance
	 * In total it creates n - 1 new states
	 * */
	public List<State> move(){
		// create empty list
		List<State> nextStates = new ArrayList<>();
		// copy the max file
		assert  serversInfo != null;
		assert dataStructure != null;
		assert dataStructure.get(maxServerID).peek() != null;
		Set<Integer> loc = serversInfo.fileLocations(dataStructure.get(maxServerID).peek().getFileID());
		assert  loc != null;
		for (Integer serverID : loc) { // for each server create a new state
			if (serverID != maxServerID) {
				// create a new State and update it
				State modified = new State(this);
				modified.moveMaxFile(serverID);
				nextStates.add(modified);
			}
		}
		return nextStates;
	}

	/**
	* This operator swaps the file from the peek of a random server and 
	* all the others where it is present to another random server
	* */
	public List<State> swap() {
		List<State> nextStates = new ArrayList<>();
		int origin = randGenerator.nextInt(dataStructure.size());
		while (dataStructure.get(origin).size() == 0)
			origin = randGenerator.nextInt(dataStructure.size());
		Set<Integer> loc = serversInfo.fileLocations(dataStructure.get(origin).peek().getFileID());
		Iterator<Integer> it = loc.iterator();

		while(it.hasNext()){ // for each server create a new state
			Integer serverID = it.next();
			if(serverID != origin){
				// create a new State and update it
				State modified = new State(this);
				modified.moveRandomFile(origin, serverID);
				nextStates.add(modified);
			}
		}

		return nextStates;
	}

	/************************************
	 * 			AUXILIARY METHODS
	 *************************************/

	private void calculateMaxAndSum(){
		maxServerID = 0; // max
		sumTransmissionTimes = (float) 0.0;
		maxTransmissionTime = (float) 0.0;

		for(int i = 0; i < nServers; ++i){
			float current = transmissionTimes.get(i);
			if(current > maxTransmissionTime){
				maxServerID = i;
				maxTransmissionTime = current;
			}
			sumTransmissionTimes += current;
		}

	}

	private void fillArrayList(){
		dataStructure = new ArrayList<>(nServers);
		transmissionTimes = new ArrayList<>(nServers);
		for(int i = 0; i < nServers; ++i){
			dataStructure.add(new PriorityQueue<>());
			transmissionTimes.add(0.0f);
		}
	}

	public String printState(){
		return "MaxTransmissionTime: " + maxTransmissionTime +
				"\nSumTransmissionTime: " + sumTransmissionTimes +
				"\nBalance: " + getSTD();
	}

	public int compare(State state) {
		for(int i = 0; i < nServers; ++i){
			if(transmissionTimes.get(i) < state.transmissionTimes.get(i)){
				return -1; // current state is less than parameter "state"
			}
			else if(transmissionTimes.get(i) > state.transmissionTimes.get(i)){
				return 1; // current state is greater
			}
		}
		return 0; // equal
	}

	/************************************
	 * 			   GETTERS
	 *************************************/

	public float getMaxTransmissionTime() {
		return maxTransmissionTime;
	}


	public float getSumTransmissionTimes(){
		return sumTransmissionTimes;
	}

	public float getSTD() {
		float mean = sumTransmissionTimes / transmissionTimes.size();
		float std = (float) 0.0; // std
		for(int i = 0; i < transmissionTimes.size(); ++i){
			float term = transmissionTimes.get(i) - mean;
			std += term * term;
		}
		std /= transmissionTimes.size() - 1;
		return std;
	}


	/************************************
	* 			ATTRIBUTES
	*************************************/


	private float sumTransmissionTimes;
	private float maxTransmissionTime;
	private int maxServerID;
	private static Random randGenerator;
	private static Servers serversInfo;
	private static int nServers;
	private ArrayList<Float> transmissionTimes;
	private ArrayList<PriorityQueue<File>> dataStructure;



}