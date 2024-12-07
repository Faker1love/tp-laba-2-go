#include "reader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

LongestWordFinder::LongestWordFinder() : longestWord(""), count(0) {
    std::cout << "LongestWordFinder constructed\n";
}

LongestWordFinder::~LongestWordFinder() {
    std::cout << "LongestWordFinder destructed\n";
}

void LongestWordFinder::processFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open file " + filename);
    }

    std::string word;
    while (file >> word) {
        // Remove punctuation
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());

        if (word.length() > longestWord.length()) {
            longestWord = word;
            count = 1;
        }
        else if (word.length() == longestWord.length() && word == longestWord) {
            ++count;
        }
    }

    file.close();
    if (longestWord.empty()) {
        throw std::runtime_error("Error: File is empty or contains no valid words.");
    }
}

void LongestWordFinder::displayResult() const {
    if (longestWord.empty()) {
        std::cout << "No words found.\n";
    }
    else {
        std::cout << "Longest word: " << longestWord << "\n"
            << "Occurrences: " << count << "\n";
    }
}
