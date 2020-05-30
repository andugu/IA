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

        Exercice(unsigned int i, unsigned int lvl, unsigned int obj);

        void addPrecursor(Exercice& ex);

        void addPreparer(Exercice& ex);

        void reset();

        bool nextPrecursor();

        bool nextPreparator();

        std::shared_ptr<Exercice> getPreparator();

        std::shared_ptr<Exercice> getPrecursor();

        unsigned int getID() const;

        unsigned int getLevel() const;

        unsigned int getObjective() const;

        void setObjective(unsigned int obj);


    private:

        // exercice name
        unsigned int id;
        // current level that the user has
        unsigned int level;
        // objective level
        unsigned int objective;
        // save relationship with other exercices
        ExerciceList precursors;
        ExerciceList preparers;
        // exercice list iterator
        ExerciceList::const_iterator precursorIt;
        ExerciceList::const_iterator preparersIt;


};
