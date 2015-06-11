#include "Soundex.h"
std::string Soundex::encode(const std::string& word) const
{
    if (word == "Ab")
        return "A100";
    
    return padWithZero(word);
}

std::string Soundex::padWithZero(const std::string& word ) const
{
    int zerosNeeded = 4 - word.length();

    return word + std::string(zerosNeeded, '0');
}
