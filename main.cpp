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
    

    // display all multimedia objects
    multimediaGroup.display(cout);

    return 0;
}
