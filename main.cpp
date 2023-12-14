//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
using namespace std;

#include "./class/Video.h"
#include "./class/Photo.h"
#include "./class/Group.h"

using MultimediaPtr = std::shared_ptr<Multimedia>;
typedef std::shared_ptr<Multimedia> MultimediaPtr;

int main(int argc, const char* argv[])
{
    // list of multimedia objects
    Group multimediaGroup{};
    multimediaGroup.add(MultimediaPtr(new Video("Video 1", "video1.mp4", 10)));
    multimediaGroup.add(MultimediaPtr(new Video("Video 2", "video2.mp4", 20)));
    multimediaGroup.add(MultimediaPtr(new Photo("Photo 1", "photo1.jpg", 100, 200)));
    multimediaGroup.add(MultimediaPtr(new Photo("Photo 2", "photo2.jpg", 200, 400)));

    // display all multimedia objects
    multimediaGroup.display(cout);

    return 0;
}
