#ifndef Soundex_h
#define Soundex_h
#include <string>

class Soundex
{
public:
  std::string encode(const std::string& word) const;


private:
    std::string head(const std::string& word ) const;

    std::string padWithZero(const std::string& word ) const;

    std::string encodeDigits(const std::string& word ) const;

    std::string encodeDigit( char letter ) const;
};

#endif
