#include <iostream>
#include <string>
#include <map>

#include "Multimedia.h"
#include "Group.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"

using MultimediaPtr = std::shared_ptr<Multimedia>;
typedef std::shared_ptr<Multimedia> MultimediaPtr;

using GroupPtr = std::shared_ptr<Group>;
typedef std::shared_ptr<Group> GroupPtr;

class Manager
{
private:
    std::map<std::string, MultimediaPtr> multimediaMap{};
    std::map<std::string, GroupPtr> groupMap{};

public:
    Manager(){};

    ~Manager();

    // Add a multimedia object to the map
    void add(MultimediaPtr multimedia)
    {
        multimediaMap[multimedia->getName()] = multimedia;
    }

    // Create a photo
    std::shared_ptr<Photo> createPhoto(std::string name, std::string fileName, int width, int height);

    // Create a video
    std::shared_ptr<Video> createVideo(std::string name, std::string fileName, int duration);

    // Create a film
    std::shared_ptr<Film> createFilm(std::string name, std::string fileName, int duration, int *chapters, int chapterCount);

    // Create a group
    std::shared_ptr<Group> createGroup(std::string name);

    void findMultimedia(std::string name);

    void findGroup(std::string name);

    // Play a multimedia object
    void play(std::string name);

    //
    void remove(std::string name);

};
