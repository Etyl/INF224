#include "Manager.h"

std::shared_ptr<Photo> Manager::createPhoto(std::string name, std::string fileName, int width, int height)
{
    std::shared_ptr<Photo> photo = std::shared_ptr<Photo>(new Photo(name, fileName, width, height));
    multimediaMap[name] = photo;
    return photo;
}

std::shared_ptr<Video> Manager::createVideo(std::string name, std::string fileName, int duration)
{
    std::shared_ptr<Video> video = std::shared_ptr<Video>(new Video(name, fileName, duration));
    multimediaMap[name] = video;
    return video;
}

std::shared_ptr<Film> Manager::createFilm(std::string name, std::string fileName, int duration, int *chapters, int chapterCount)
{
    std::shared_ptr<Film> film = std::shared_ptr<Film>(new Film(name, fileName, duration, chapters, chapterCount));
    multimediaMap[name] = film;
    return film;
}

std::shared_ptr<Group> Manager::createGroup(std::string name)
{
    std::shared_ptr<Group> group = std::shared_ptr<Group>(new Group(name));
    groupMap[name] = group;
    return group;
}

// display multimedia, else display error message
void Manager::findMultimedia(std::string name, std::ostream &stream) {
    std::map<std::string,MultimediaPtr>::iterator searchList = multimediaMap.find(name);
    if (searchList == multimediaMap.end()) {
        stream << "Error: could not find Multimedia" << std::endl;
    }
    else {
        multimediaMap[name]->display(stream);
    }
}

// display a group
void Manager::findGroup(std::string name, std::ostream &stream) {
    auto searchList = groupMap.find(name);
    if (searchList == groupMap.end()) {
        stream << "Error: could not find Group" << std::endl;
    }
    else {
        groupMap[name]->display(stream);
    }
}

// play multimedia, else display error message
void Manager::play(std::string name) {
    auto searchList = multimediaMap.find(name);
    if (searchList == multimediaMap.end()) {
        std::cout << "Error: could not find Multimedia" << std::endl;
    }
    else {
        multimediaMap[name]->play();
    }
}

// remove multimedia, else display error message
void Manager::remove(std::string name) {
    auto search = multimediaMap.find(name);
    if (search == multimediaMap.end()) {
        std::cout << "Error: could not find Multimedia" << std::endl;
    }
    else {
        // remove multimedia from group
        for (auto group : groupMap) {
            group.second->remove(multimediaMap[name]);
        }
        multimediaMap.erase(name);
    }
}