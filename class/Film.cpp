#include "Film.h"

// Constructor
Film::Film(const std::string &name, const std::string &path, int length, int *chapterLengths, int chapterLengthsSize)
    : Video(name, path, length), chapterLengthsSize(chapterLengthsSize)
{
    this->chapterLengths = new int[chapterLengthsSize];
    for (int i = 0; i < chapterLengthsSize; i++)
    {
        this->chapterLengths[i] = chapterLengths[i];
    }
};

// Getter and setter for chapterLengths
int *Film::getChapterLengths() const
{
    int *newChapterLengths = new int[chapterLengthsSize];
    for (int i = 0; i < chapterLengthsSize; i++)
    {
        newChapterLengths[i] = chapterLengths[i];
    }
    return newChapterLengths;
}
void Film::setChapterLengths(int *newChapterLengths, int newChapterLengthsSize)
{
    chapterLengthsSize = newChapterLengthsSize;
    if (chapterLengths != nullptr)
    {
        delete[] chapterLengths;
        chapterLengths = nullptr;
    }
    chapterLengths = new int[newChapterLengthsSize];
    for (int i = 0; i < newChapterLengthsSize; i++)
    {
        chapterLengths[i] = newChapterLengths[i];
    }
}

// Display method
void Film::display(std::ostream &os) const
{
    Video::display(os);
    os << "Chapter lengths: ";
    for (int i = 0; i < chapterLengthsSize; i++)
    {
        os << chapterLengths[i] << " ";
    }
    os << std::endl;
}