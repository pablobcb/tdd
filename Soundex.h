#ifndef Soundex_h
#define Soundex_h
#include <string>

class Soundex
{
public:
    std::string encode( const std::string& word) const;

    char encodeDigit( char letter ) const;


private:
    std::string encodeDigits( const std::string& word ) const;

    bool isComplete( const std::string& enconding ) const;

    std::string padWithZero( const std::string& word ) const;

    char head( const std::string& word ) const;

    std::string tail( const std::string& word ) const;

    std::string encodeHead( const std::string& word ) const;

    std::string encodeTail( const std::string& word ) const;

    void encodeLetter( std::string& enconding, const char letter ) const;

    char lastDigit( const std::string& word ) const;

    char lower(char c) const;

    char upper(char c) const;

};

#endif
