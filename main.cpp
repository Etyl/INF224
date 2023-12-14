//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
using namespace std;

#include "./class/Video.h"
#include "./class/Photo.h"



int main(int argc, const char* argv[])
{
    // list of multimedia objects
    Multimedia* multimediaList[4];
    multimediaList[0] = new Video("Video 1", "video1.mp4", 10);
    multimediaList[1] = new Video("Video 2", "video2.mp4", 20);
    multimediaList[2] = new Photo("Photo 1", "photo1.jpg", 10, 20);
    multimediaList[3] = new Photo("Photo 2", "photo2.jpg", 20, 30);

    // display all multimedia objects
    for (int i = 0; i < 4; i++) {
        multimediaList[i]->display(cout);
    }

    return 0;
}
