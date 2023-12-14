#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>

class Multimedia
{
private:
    std::string name{};
    std::string fileName{};

public:
    Multimedia(const std::string &name, const std::string &fileName);
    Multimedia();

    // Setter for name
    void setName(const std::string &newName);

    // Getter for name
    std::string getName() const;

    // Setter for fileName
    void setFileName(const std::string &newFileName);

    // Getter for fileName
    std::string getFileName() const;

    // Display method
    virtual void display(std::ostream &os) const;

    // Destructor
    ~Multimedia();

    // Virtual play method
    virtual void play() const = 0;
};

#endif // MULTIMEDIA_H
