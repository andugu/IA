

public class State{



	public State(){

	}

	public State(State s){
		s.maxServerID = maxServerID;
		s.dataStructure = dataStructure;
		s.transmissionTimes = transmissionTimes;
	}

	public void initialState1(Servers servers, Requests requests){
		serversInfo = servers;
		transmissionTimes = new ArrayList<Integer>(Collections.nCopies(servers.size(), 0));
		dataStructure = new ArrayList<Set<fileID>>(servers.size());

		for(int i = 0; i < requests.size(); ++i){
			int[] req = requests.getRequest(i); //[userID, fileID]
			Set<Integer> loc = servers.fileLocations(req[1]);
			Iterator<Integer> it = loc.iterator();
			float min = 5001; 
			float minServer = 0;
			while(it.hasNext()){
				Integer serverID = it.next();
				float current = servers.transmissionTime(serverID, req[0]);
				if(min > current){
					minServer = serverID;
					min = current;
				}
			}
			
			dataStructure[minServer].add(fileID);
			transmissionTimes[minServer] += min;
		}
		calculateMaxAndSum()
	}

	public void initialState2(Servers servers, Requests requests){


	}

	private void calculateMaxAndSum(){
		maxServerID = 0; // max
		sumTransmissionTimes = 0.0;
		maxTransmissionTime = 0.0;
		for(int i = 0; i < transmissionTimes.size(); ++i){
			float current = transmissionTimes[i];
			if(current > maxTransmissionTime){
				maxServerID = i;
				maxTransmissionTime = current;
			}
			sumTransmissionTimes += current;
		}	

	}


	/******************************************************
	*					not here!
	******************************************************/
	
	public float heuristic(){
		float h1 = maxTransmissionTime;
		float h2 = sumTransmissionTimes;
		float mean = sumTransmissionTimes / transmissionTimes.size();	
		float h3 = 0.0; // std
		for(int i = 0; i < transmissionTimes.size(); ++i){
			float term = transmissionTimes[i] - mean;
			h3 += term * term
		}
		h3 /= transmissionTimes.size() - 1;
		return h1 + h2  + h3; 
	}


	public void operatorA(){
		

	}

	/******************************************************
	*					END not here!
	******************************************************/

	private float sumTransmissionTimes;
	private float maxTransmissionTime;
	private int maxServerID;
	private static Servers serversInfo;
	private ArrayList<Integer> transmissionTimes; 
	private ArrayList<Set<fileID>> dataStructure;

}