package src;

import IA.DistFS.Requests;
import IA.DistFS.Servers;

import java.util.*;

public class State{




	public State(){

	}

	public State(State s){
		maxServerID = s.maxServerID;
		dataStructure = s.dataStructure;
		transmissionTimes = s.transmissionTimes;
	}

	/************************************
	 * 			INITIAL STATES
	 *************************************/

	/**
	 * @brief Initializes each request to the server with the fastest user-server transmission
	 * */
	public void initialState1(Servers servers, Requests requests){
		serversInfo = servers;
		transmissionTimes = new ArrayList<Float>();
		fillArrayList();

		System.out.println("Total servers: " + servers.size());
		System.out.println("Data structure size: " + dataStructure.size());
		for(int i = 0; i < requests.size(); ++i){
			int[] req = requests.getRequest(i); //[userID, fileID]
			Set<Integer> loc = servers.fileLocations(req[1]);
			Iterator<Integer> it = loc.iterator();
			float min = 5001;
			int minServer = 0;
			while(it.hasNext()){
				Integer serverID = it.next();
				var current = servers.tranmissionTime(serverID, req[0]);
				if(min > current){
					minServer = serverID;
					min = current;
				}
			}
			System.out.println("Fastest Server: " + minServer);
			dataStructure.get(minServer).add(req[1]); // <= SEG FAULT
			transmissionTimes.set(minServer, transmissionTimes.get(minServer) + min);
		}
		calculateMaxAndSum();
	}

	public void initialState2(Servers servers, Requests requests){


	}

	/************************************
	 * 			OPERATORS
	 *************************************/

	public void operatorA(){


	}

	/************************************
	 * 			AUXILIARY METHODS
	 *************************************/

	private void calculateMaxAndSum(){
		maxServerID = 0; // max
		sumTransmissionTimes = (float) 0.0;
		maxTransmissionTime = (float) 0.0;
		for(int i = 0; i < transmissionTimes.size(); ++i){
			float current = transmissionTimes.get(i);
			if(current > maxTransmissionTime){
				maxServerID = i;
				maxTransmissionTime = current;
			}
			sumTransmissionTimes += current;
		}

	}

	private void fillArrayList(){
		dataStructure = new ArrayList<>(serversInfo.size());
		transmissionTimes = new ArrayList<>(serversInfo.size());
		for(int i = 0; i < serversInfo.size(); ++i){
			dataStructure.add(new HashSet<>());
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
	private ArrayList<Float> transmissionTimes;
	private ArrayList<Set<Integer>> dataStructure;



}