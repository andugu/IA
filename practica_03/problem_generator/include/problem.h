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

        void addExercice(Exercice& ex);

        void write(std::string const& fileName) const;

    private:
 
        std::string writeDomain() const;
        std::string writeObjects() const;
        std::string writeInit() const;
        std::string writeGoal() const;

        std::string writeStatement(std::string const& header, std::string const& content = "", std::string const& end ="\n") const;

        /* Name of the domain to address*/
        std::string domain;

        /* List of exercices of the current problem*/
        std::list<Exercice> exercices;


};
