package src;

import IA.DistFS.Requests;
import IA.DistFS.Servers;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.Set;

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

	public void initialState1(Servers servers, Requests requests){
		serversInfo = servers;
		transmissionTimes = new ArrayList<Float>();
		fillArrayList(transmissionTimes, (float)0.0, servers.size());
		dataStructure = new ArrayList<Set<Integer>>(servers.size());

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
			
			// dataStructure.get(minServer).add(req[1]); // <= SEG FAULT
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

	private void fillArrayList(ArrayList<Float> list, float value, int repetitions){
		for(int i = 0; i < repetitions; ++i){
			list.add(value);
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