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
    file << writeStatement("define", writeStatement("problem") +
        writeDomain() +
        writeObjects() +
        writeInit() +
        writeGoal()
    );

}


void Problem::addExercice(Exercice& ex){
    exercices.push_back(ex); 
}


/*******************
 *     PRIVATE
 ********************/


 std::string Problem::writeDomain() const{
     return writeStatement(":domain", domain);
 }


 std::string Problem::writeObjects() const{
     return writeStatement(":objects");
 }

 std::string Problem::writeInit() const{
     return writeStatement(":init");
 }


 std::string Problem::writeGoal() const{
     return writeStatement(":goal");
 }

std::string Problem::writeStatement(std::string const& header, std::string const& content, std::string const& end) const{
    return "(" + header + content + ")" + end;
}
