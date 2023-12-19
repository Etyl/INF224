#include "Film.h"

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
    delete[] chapterLengths;
    chapterLengths = new int[newChapterLengthsSize];
    for (int i = 0; i < newChapterLengthsSize; i++)
    {
        chapterLengths[i] = newChapterLengths[i];
    }
}