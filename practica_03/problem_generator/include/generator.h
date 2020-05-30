#include <vector>

#include "problem.h"

/**
 * Class that manages the creation of
 * specific problems
 * */
class Generator{


    public:

        Generator() = default;

        Generator(unsigned int randSeed);


        Problem generate(std::string const& domainName, unsigned int nExercices,
                         unsigned int maxPrecursors, unsigned int maxPredecesors,
                         bool hasDuration);


    private:

        // percentatge of exercices that will have
        // an objective
        float pObjective;
        unsigned int seed;

};
