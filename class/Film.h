#include "Video.h"

class Film : public Video {
private:

        int* chapterLengths{};
        int chapterLengthsSize{};

    public:
        Film(const std::string& name, const std::string& path, int length, int* chapterLengths, int chapterLengthsSize)
            : Video(name, path, length), chapterLengths(chapterLengths), chapterLengthsSize(chapterLengthsSize) {} ;
        
        Film() {};

        // Getter and setter for chapterLengths
        int* getChapterLengths() const {
            int* newChapterLengths = new int[chapterLengthsSize];
            for (int i = 0; i < chapterLengthsSize; i++) {
                newChapterLengths[i] = chapterLengths[i];
            }
            return newChapterLengths;
        }
        void setChapterLengths(int* newChapterLengths, int newChapterLengthsSize) {
            chapterLengthsSize = newChapterLengthsSize;
            delete[] chapterLengths;
            chapterLengths = new int[newChapterLengthsSize];
            for (int i = 0; i < newChapterLengthsSize; i++) {
                chapterLengths[i] = newChapterLengths[i];
            }
        }

};