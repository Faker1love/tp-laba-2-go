#ifndef READER_H
#define READER_H

#include <string>

class LongestWordFinder {
private:
    std::string longestWord;
    int count;

public:
    LongestWordFinder();
    void processFile(const std::string& filename);
    void displayResult() const;
    ~LongestWordFinder();
};

#endif // LONGESTWORDFINDER_H
