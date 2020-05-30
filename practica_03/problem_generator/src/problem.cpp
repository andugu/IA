#include "../include/problem.h"





/*******************
 *     PUBLIC
 ********************/

Problem::Problem(std::string const& domainName){
    domain = domainName;
}

void Problem::write(std::string const& fileName){
    std::ofstream file(fileName); // RAII -> not closing necessary
    file << ";; Generated problem " << fileName << std::endl;
    file << writeStatement("define", writeStatement("problem", " nivel_basico") +
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
     std::string objects = "\n";
     // add exercices

     for(auto const& e : exercices){
         objects += " e" + std::to_string(e.getID());
     }
     objects += " - ejercicio\n";
     // add levels
     auto it = 0;
     for(it = 1; it <= MAX_LEVEL; ++it){
         objects += " n" + std::to_string(it);
     }
     objects += " - nivel\n";
     // add days
     for(it = 1; it <= MAX_DAYS; ++it){
         objects += " d" + std::to_string(it);
     }
     objects += " - dia\n";

     return writeStatement(":objects", objects);
 }

std::string Problem::writeInit(){
     std::string objects = "";
     // add exercices relationships
     for(auto& e : exercices){
         e.reset(); // reset iterators
         // add precursors
         auto id = " e" + std::to_string(e.getID());

         while(e.nextPrecursor()){
             auto exercice = e.getPrecursor();
             auto idP = " e"  + std::to_string(exercice->getID());
             objects += writeStatement("precursor", idP + id, " ");
         }
         // add preparators
         while(e.nextPreparator()){
             auto exercice = e.getPreparator();
         }
         auto level = "n" + std::to_string(e.getLevel());
         std::string content = " " + level + id;
         objects += writeStatement("dificultad", content, ";; exercice " + id + "\n");

     }
     objects += "\n";
     // add level relationships
     for(auto i = 2; i <= MAX_LEVEL; ++i){
         auto content = " n" + std::to_string(i - 1) + " n" + std::to_string(i);
         objects += writeStatement("sig", content , " ");
     }
     objects += "\n";
     // add day relationships
     for(auto i = 2; i <= MAX_DAYS; ++i){
         auto content = " d" + std::to_string(i - 1) + " d" + std::to_string(i);
         objects += writeStatement("ant", content , " ");
     }
     objects += "\n";

     // add first day
     objects += writeStatement("primer_dia d1");
     return writeStatement(":init", objects);
 }


 std::string Problem::writeGoal() const{
     std::string objects = "";
     for(auto const& e : exercices){
         auto level = "n" + std::to_string(e.getLevel());
         auto objective = "n" + std::to_string(e.getObjective());
         if(level != objective){
            objects += writeStatement("conseguido", " e" + std::to_string(e.getID()));
         }
     }

     return writeStatement(":goal", writeStatement("and", objects));
 }

std::string Problem::writeStatement(std::string const& header, std::string const& content, std::string const& end) const{
    return "(" + header + content + ")" + end;
}
