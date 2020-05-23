#include "../include/exercice.h"

/*******************
 *      PUBLIC
 *********************/


void Exercice::addPrecursor(Exercice& ex){
    precursors.push_back(std::make_shared<Exercice> (ex)); 
}


void Exercice::addPreparer(Exercice& ex){
    preparers.push_back(std::make_shared<Exercice> (ex)); 
}



/*******************
 *       PRIVATE
 *********************/
