/**
 * Coaching Potato Problem Generator
 * Given a set of parameters this program generates 
 * a problem 
 * 
 * */
#include <iostream> 
#include <string>

/* Constants definitions */
const int MIN_ARGS = 2; 

/**
 * Usage function: 
 *  Displayed when the user supplied 
 *  wrong arguments 
 * */
void usage(){
    std::cout << std::endl << "Usage: generator arg1 arg2.. " << std::endl; 
     
    
}


/**
 * Main function:
 *  Entry point to the program 
 * */
int main(int argc, char* argv[]){
    
    if(argc < MIN_ARGS){
        usage();
        return EXIT_FAILURE; 
    }  
    
    std::string outFile = argv[1]; 

    return 0; 
}
