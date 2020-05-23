#include "problem.h"

/**
 * Class that manages the creation of
 * specific problems
 * */
class Generator{


    public:

        Generator() = default;

        Generator(unsigned int randSeed);


        Problem generate(std::string const& domainName, unsigned int nExercices);


    private:

        unsigned int seed;

};
