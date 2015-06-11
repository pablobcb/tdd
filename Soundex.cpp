#include "Soundex.h"

std::string Soundex::encode(const std::string& word) const
{
  return padWithZero(head(word) + encodeDigits(word));
}

std::string Soundex::padWithZero(const std::string& word ) const
{
    int zerosNeeded = 4 - word.length();

    return word + std::string(zerosNeeded, '0');
}


std::string Soundex::encodeDigits( const std::string& word ) const
{
    if( word.length() > 1)
      return "1";

    return "";
}


std::string Soundex::head( const std::string& word ) const
{
    return word.substr( 0, 1 );
}
