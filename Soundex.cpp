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
    return encoding.length() == maxCodeLength;
}


std::string Soundex::encode(const std::string& word) const
{
    return padWithZero(
        upper( head ( word ) ) + encodeDigits( tail( word ) )
    );
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

std::string Soundex::encodeDigits( const std::string& tail ) const
{
    printf("[tail]:  %s \n", tail.c_str());
    std::string encoding = "";
    //encoding += encodeDigit( tail[ 0 ] );


    printf("[size]:  %d \n", tail.size());
    for ( size_t i = 0 ; i < tail.size() ; i++ )
    {
        if ( isComplete( encoding ) )
            break;

        const char digit = encodeDigit( tail[ i ] );
        const char last= lastDigit( encoding );

        if ( digit != notDigit 
          //&& last != notDigit
          //&& last != digit
        ){
            encoding += digit;
        }
        //printf("[word[%d]]:  %c \n", i, digit);
//
//        //printf("[digit]:  %c \n", digit);
//        //printf("[last digit]: %c \n" , lastDigit(encoding));
        //printf("[encoding]:  %s\n", encoding.c_str());

    }

    printf("[ret encoding]:  %s\n", encoding.c_str());
    return encoding;
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


