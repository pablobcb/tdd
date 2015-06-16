#include "Soundex.h"
#include <map>
#include <stdio.h>
//#include <boost\assign.hpp>

const size_t maxCodeLength = 4 ;

char notDigit = '*';


std::string Soundex::padWithZero(const std::string& word ) const
{
    size_t zerosNeeded = maxCodeLength - word.length();

    return word + std::string(zerosNeeded, '0');
}


bool Soundex::isComplete( const std::string& encoding ) const
{
    return encoding.length() == maxCodeLength - 1;
}


std::string Soundex::encode(const std::string& word) const
{
    char front = upper( head ( word ) );

    std::string rest = encodeDigits( word );

    return padWithZero(front + rest);
}


char Soundex::encodeDigit( const char letter ) const
{
    std::map< char, char > encodings;
    // = boost::assign::map_list_of(1 , new MyObject(1))(2, new MyObject(2))(3, new MyObject(3));s

    encodings.insert( std::make_pair( 'b', '1' ) );

    encodings.insert( std::make_pair( 'c', '2' ) );

    encodings.insert( std::make_pair( 'f', '1' ) );

    encodings.insert( std::make_pair( 'p', '1' ) );

    encodings.insert( std::make_pair( 'v', '1' ) );

    encodings.insert( std::make_pair( 'g', '2' ) );

    encodings.insert( std::make_pair( 'j', '2' ) );

    encodings.insert( std::make_pair( 'k', '2' ) );

    encodings.insert( std::make_pair( 'q', '2' ) );

    encodings.insert( std::make_pair( 's', '2' ) );

    encodings.insert( std::make_pair( 'x', '2' ) );

    encodings.insert( std::make_pair( 'z', '2' ) );

    encodings.insert( std::make_pair( 'd', '3' ) );

    encodings.insert( std::make_pair( 't', '3' ) );

    encodings.insert( std::make_pair( 'l', '4' ) );

    encodings.insert( std::make_pair( 'm', '5' ) );

    encodings.insert( std::make_pair( 'n', '5' ) );

    encodings.insert( std::make_pair( 'r', '6' ) );

    const char loweredLetter = lower( letter );

    std::map< char, char >::iterator it = encodings.find( loweredLetter );

    if( it == encodings.end() )
        return notDigit;
   
    char c = (it)->second;

    return c;
}


std::string Soundex::encodeHead( const std::string& word ) const
{
    const char front = lower( word[ 0 ] );

    std::string rest = tail( word );

    if ( front == rest[ 0 ] )
        rest = tail( rest );

    return rest;
}

std::string Soundex::encodeTail( const std::string& word ) const
{
    std::string encoding = "";

    for ( size_t i = 0 ; i < word.size() ; i++ )
    {
        if ( isComplete( encoding ) )
            break;
        encodeLetter( encoding, word[ i ]);
    }

    return encoding;
}

void Soundex::encodeLetter(std::string& encoding, const char letter) const
{
    const char digit = encodeDigit( letter );
    const char last  = lastDigit( encoding );

    if ( digit != notDigit && last != digit)
      encoding += digit;

}


std::string Soundex::encodeDigits( const std::string& word ) const
{
    return encodeTail( encodeHead( word ) );
}


char Soundex::lastDigit( const std::string& encoding ) const
{
    if ( encoding.empty() )
        return notDigit;

    return encoding[ encoding.size() -1 ];
}


char Soundex::head( const std::string& word ) const
{
    return word[ 0 ];
}


std::string Soundex::tail( const std::string& word ) const
{
    return word.substr( 1 );
}


char Soundex::lower( const char c ) const {
    return std::tolower( static_cast< unsigned char >( c ) );
}


char Soundex::upper( const char c ) const {
    return std::toupper( static_cast< unsigned char >( c ) ) ;
}


