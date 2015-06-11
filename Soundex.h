#ifndef Soundex_h
#define Soundex_h
#include <string>

class Soundex
{
public:
  std::string encode(const std::string& word) const;


private:
  std::string padWithZero(const std::string& word ) const;
};

#endif
