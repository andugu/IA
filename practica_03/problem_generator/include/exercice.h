#include <list>
#include <memory>

/**
 * Exercice class has information about itself, 
 * its precursors and preparers  
 *
 * */
class Exercice{


    public:

        typedef std::list<std::shared_ptr<Exercice>> ExerciceList; 

        void addPrecursor(Exercice& ex); 

        void addPreparer(Exercice& ex); 
        

    private:

        ExerciceList precursors; 
        ExerciceList preparers; 


}; 
