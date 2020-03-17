package src;

import IA.DistFS.Requests;
import IA.DistFS.Servers;

import java.util.*;

public class State{


	public State(){}

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
			int[] req = requests.getRequest(i); //[userID, fileID
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
			dataStructure.get(minServer).add(currentFile); // <= SEG FAULT
			transmissionTimes.set(minServer, transmissionTimes.get(minServer) + min);
		}
		calculateMaxAndSum();
	}

	public void initialState2(Servers servers, Requests requests){


	}

	/************************************
	 * 			OPERATORS
	 *************************************/

	public void moveMaxFile(int newLocation){
		// get max file
		File maxFile = dataStructure.get(maxServerID).poll();
		// update transmission times
		if(maxFile == null){
			System.out.println(maxServerID);
		}
		int userID = maxFile.getUserID();
		float newTransmissionTime = serversInfo.tranmissionTime(newLocation, userID);
		transmissionTimes.set(maxServerID, transmissionTimes.get(maxServerID) - maxFile.getTransmissionTime());
		maxFile.setTransmissionTime(newTransmissionTime);
		dataStructure.get(newLocation).add(maxFile);
		// recalculate variables
		calculateMaxAndSum();
	}


	/**
	 * This move operator selects the file with the lowest
	 *transmission time from the lowest server and moves it into n - 1
	 *servers (to the rest of the servers) this operator tries to minimize
	 *the transmission time and create a balance
	 *In total it creates n - 1 new states
	 * */
	public List<State> move(){
		// create empty list
		List<State> nextStates = new ArrayList<>();
		// copy the max file
		for(int i = 0; i < nServers; ++i){ // for each server create a new state
			if(i != maxServerID){
				// create a new State and update it
				State modified = new State(this);
				modified.moveMaxFile(i);
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

	public void printState(){
		System.out.println("State print not implemented!");
	}


	/************************************
	 * 			GETTERS
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
	private static Servers serversInfo;
	private static int nServers;
	private ArrayList<Float> transmissionTimes;
	// !!!!!!!!!!!!!!!!!!
	private ArrayList<PriorityQueue<File>> dataStructure; // IMPORTANT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
	// WHICH IS THE ORDERING????



}