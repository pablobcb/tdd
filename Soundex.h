#ifndef Soundex_h
#define Soundex_h
#include <string>

class Soundex
{
public:
    std::string encode( const std::string& word) const;

    std::string encodeDigit( char letter ) const;


private:

    char lower(char c) const;

    char upper(char c) const;

    std::string upperFront( const std::string& str ) const;

    std::string head( const std::string& word ) const;

    std::string tail( const std::string& word ) const;

    std::string lastDigit( const std::string& word ) const;

    std::string padWithZero( const std::string& word ) const;

    bool isComplete( const std::string& enconding ) const;

    std::string encodeDigits( const std::string& word ) const;
};

#endif
