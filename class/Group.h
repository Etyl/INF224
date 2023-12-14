#include <list>
#include <memory>

#include "Multimedia.h"

using MultimediaPtr = std::shared_ptr<Multimedia>;
typedef std::shared_ptr<Multimedia> MultimediaPtr;

class Group 
{
private:
    std::list<MultimediaPtr> multimediaList;

public:
    // Constructor
    Group() {};

    // Destructor
    ~Group() {};

    // Add a multimedia object to the list
    void add(MultimediaPtr multimedia) {
        multimediaList.push_back(multimedia);
    }

    // Remove a multimedia object from the list
    void remove(MultimediaPtr multimedia) {
        multimediaList.remove(multimedia);
    }

    // Display all multimedia objects in the list
    void display(std::ostream& os) const {
        for (auto multimedia : multimediaList) {
            multimedia->display(os);
        }
    }

};