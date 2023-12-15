#include "Multimedia.h"

class Video : public Multimedia
{
private:
    int length{};

protected:
    // Constructor
    Video(const std::string &name, const std::string &path, int length)
        : Multimedia(name, path), length(length){};

    // Default constructor
    Video(){};

    // Friend class
    friend class Manager;

public:
    // Getter and setter for length
    int getLength() const { return length; }
    void setLength(int newLength) { length = newLength; }

    // Display method
    void display(std::ostream &os) const override
    {
        Multimedia::display(os);
        os << "Length: " << length << std::endl;
    }

    // Play method
    void play() const override
    {
        std::string command = "mpv " + getFileName() + " &";
        system(command.c_str());
    }

    // Destructor
    ~Video(){};
};
