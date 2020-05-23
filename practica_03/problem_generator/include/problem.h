#include <string>
#include <list>
#include <fstream> 

#include "exercice.h"

/**
 * The problem class represents a set of exercice from
 * which the planner has to solve
 * */
class Problem{


    public:

        Problem() = default;

        explicit Problem(std::string const& domainName);

        void write(std::string const& fileName) const;

    private:

        /* Name of the domain to address*/
        std::string domain;

        /* List of exercices of the current problem*/
        std::list<Exercice> exercices;


};
