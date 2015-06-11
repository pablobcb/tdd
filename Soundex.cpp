#include "Soundex.h"
std::string Soundex::encode(const std::string& word) const
{
  return padWithZero(word);
}

std::string Soundex::padWithZero(const std::string& word ) const
{
  return word + "000";
}
