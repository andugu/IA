#include "../include/problem.h"





/*******************
 *     PUBLIC
 ********************/

Problem::Problem(std::string const& domainName){
    domain = domainName;
}

void Problem::write(std::string const& fileName) const{
    std::ofstream file(fileName); // RAII -> not closing necessary
    file << ";; Generated problem " << fileName << std::endl;
}


/*******************
 *     PRIVATE
 ********************/
