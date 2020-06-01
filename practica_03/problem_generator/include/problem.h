#ifndef PROBLEM_H
#define PROBLEM_H

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

        static const unsigned int MAX_DAYS = 15;
        static const unsigned int MAX_LEVEL = 10;

        Problem() = default;

        explicit Problem(std::string const& domainName);

        void addExercice(Exercice& ex);

        void setType(bool hasDuration, bool hasDayLimit);

        void write(std::string const& fileName) ;

    private:

        std::string writeDomain() const;
        std::string writeObjects() const;
        std::string writeInit();
        std::string writeGoal() const;

        std::string writeStatement(std::string const& header, std::string const& content = "", std::string const& end ="\n") const;

        bool hasDuration;
        bool hasDayLimit;

        /* Name of the domain to address*/
        std::string domain;

        /* List of exercices of the current problem*/
        std::list<Exercice> exercices;



};


#endif
