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

        Exercice();

        Exercice(unsigned int i, std::string const& lvl, std::string const& obj);

        void addPrecursor(Exercice& ex);

        void addPreparer(Exercice& ex);

        void reset();

        bool nextPrecursor();

        bool nextPreparator();

        std::shared_ptr<Exercice> getPreparator();

        std::shared_ptr<Exercice> getPrecursor();

        unsigned int getID() const;

        std::string getLevel() const;

        std::string getObjective() const; 


    private:

        // exercice name
        unsigned int id;
        // current level that the user has
        std::string level;
        // objective level
        std::string objective;
        // save relationship with other exercices
        ExerciceList precursors;
        ExerciceList preparers;
        // exercice list iterator
        ExerciceList::const_iterator precursorIt;
        ExerciceList::const_iterator preparersIt;


};
