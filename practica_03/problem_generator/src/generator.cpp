#include "../include/generator.h"



/*******************
 *    PUBLIC
 *******************/


Generator::Generator(unsigned int randSeed){
    seed = randSeed;
}

Problem Generator::generate(std::string const& domainName, unsigned int nExercices){
    Problem p;
    for(auto i = 0; i < nExercices; ++i){
        Exercice e(i, "n1", "n3");
        p.addExercice(e);
    }

    return p;
}

/*******************
 *    PRIVATE
 *******************/
