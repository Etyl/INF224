#include "Multimedia.h"

class Photo : public Multimedia
{
private:
    int latitude{};
    int longitude{};

    // Constructor
    Photo(const std::string &name, const std::string &path, int latitude, int longitude)
        : Multimedia(name, path), latitude(latitude), longitude(longitude){};

    // Default constructor
    Photo(){};

    // Friend class
    friend class Manager;

public:
    // Destructor
    ~Photo(){};

    // Getter and setter for latitude
    int getLatitude() const { return latitude; }
    void setLatitude(int newLatitude) { latitude = newLatitude; }

    // Getter and setter for longitude
    int getLongitude() const { return longitude; }
    void setLongitude(int newLongitude) { longitude = newLongitude; }

    // Display method
    void display(std::ostream &os) const override
    {
        Multimedia::display(os);
        os << "Latitude: " << latitude << std::endl;
        os << "Longitude: " << longitude << std::endl;
    }

    // Play method
    void play() const override
    {
        std::string command = "imagej " + getFileName() + " &";
        system(command.c_str());
    }
};
