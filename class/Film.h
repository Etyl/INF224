#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video
{
private:
    int *chapterLengths = nullptr;
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

    // Display method
    void display(std::ostream &os) const override;

};

#endif // FILM_H