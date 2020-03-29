package src;

import java.util.Comparator;

/**
 * Represents a copy of file in a server, a file
 * has a transmission time, an id an the id of the
 * user it requested it
 * */
public class File implements Comparable<File> {

    /**
     * A basic constructor of a file
     * */
    public File(int uID, int fID){
        userID = uID;
        fileID = fID;
    }

    /**
     * Copies a file into a new one
     * */
    public File(File copy){
        userID = copy.userID;
        fileID = copy.fileID;
        transmissionTime = copy.transmissionTime;
    }

    public float getTransmissionTime(){
        return transmissionTime;
    }

    public void setTransmissionTime(float time){
        transmissionTime = time;
    }

    public int getUserID(){
        return userID;
    }

    public int getFileID(){
        return fileID;
    }


    @Override
    public int compareTo(File f2) {
        if(transmissionTime == f2.transmissionTime)return 0;
        else if(transmissionTime < f2.transmissionTime) return -1;
        else return 1;
    }

    private float transmissionTime;
    private int userID;
    private int fileID;



}
