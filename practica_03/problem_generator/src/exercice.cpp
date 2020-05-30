#include "../include/exercice.h"

/*******************
 *      PUBLIC
 *********************/

Exercice::Exercice(){
    level = "0";
    objective = "0";
}

Exercice::Exercice(unsigned int i, std::string const& lvl, std::string const& obj){
    level = lvl;
    objective = obj;
    id = i;
}

void Exercice::addPrecursor(Exercice& ex){
    precursors.push_back(std::make_shared<Exercice> (ex));
}


void Exercice::addPreparer(Exercice& ex){
    preparers.push_back(std::make_shared<Exercice> (ex));
}

bool Exercice::nextPrecursor(){
    precursorIt++;
    return precursorIt != precursors.end();

}

bool Exercice::nextPreparator(){
    preparersIt++;
    return preparersIt != preparers.end();
}

std::shared_ptr<Exercice> Exercice::getPreparator(){
    return *preparersIt;
}

std::shared_ptr<Exercice> Exercice::getPrecursor(){
    return *precursorIt;
}

unsigned int Exercice::getID() const{
    return id;
}

void Exercice::reset(){
    precursorIt = precursors.begin();
    preparersIt = preparers.begin();
}



/*******************
 *       PRIVATE
 *********************/
