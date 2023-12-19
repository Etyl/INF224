#include "Video.h"

class Film : public Video
{
private:
    int *chapterLengths{};
    int chapterLengthsSize{};

    Film(const std::string &name, const std::string &path, int length, int *chapterLengths, int chapterLengthsSize)
        : Video(name, path, length), chapterLengths(chapterLengths), chapterLengthsSize(chapterLengthsSize){};

    Film(){};

    friend class Manager;

public: 
    // Destructor
    ~Film(){
        delete[] chapterLengths;
    };

    // Getter and setter for chapterLengths
    int *getChapterLengths() const;
    void setChapterLengths(int *newChapterLengths, int newChapterLengthsSize);

};