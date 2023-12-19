//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
using namespace std;

#include "./class/Video.h"
#include "./class/Photo.h"
#include "./class/Group.h"
#include "./class/Film.h"
#include "./class/Manager.h"

using MultimediaPtr = std::shared_ptr<Multimedia>;
typedef std::shared_ptr<Multimedia> MultimediaPtr;

int main(int argc, const char* argv[])
{
    int chapterLengths[3] = {1, 2, 3};

    Manager *manager = new Manager();
    manager->createFilm("film1", "film1.mp4", 10, chapterLengths, 3);

    manager->findMultimedia("film1");    

    return 0;
}
