#include <iostream>
#include <string>

#include "./Multimedia.h"


Multimedia::Multimedia(const std::string &name, const std::string &fileName)
    : name(name), fileName(fileName) {}

Multimedia::Multimedia() {}

// Setter for name
void Multimedia::setName(const std::string &newName)
{
    name = newName;
}

// Getter for name
std::string Multimedia::getName() const
{
    return name;
}

// Setter for fileName
void Multimedia::setFileName(const std::string &newFileName)
{
    fileName = newFileName;
}

// Getter for fileName
std::string Multimedia::getFileName() const
{
    return fileName;
}

// Display method
void Multimedia::display(std::ostream &os) const
{
    os << "Name: " << name << std::endl;
    os << "File Name: " << fileName << std::endl;
}

// Destructor
Multimedia::~Multimedia() {}

