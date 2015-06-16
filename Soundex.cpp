#include "Soundex.h"
#include <map>
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
    return padWithZero(
        upperFront( head ( word ) ) + encodeDigits( tail( word ) ) 
    );
}


std::string Soundex::encodeDigit( char letter ) const
{
    std::map< char, std::string > encodings;
    // = boost::assign::map_list_of(1 , new MyObject(1))(2, new MyObject(2))(3, new MyObject(3));s

    encodings.insert( std::make_pair( 'b', "1" ) );

    encodings.insert( std::make_pair( 'c', "2" ) );

    encodings.insert( std::make_pair( 'f', "1" ) );

    encodings.insert( std::make_pair( 'p', "1" ) );

    encodings.insert( std::make_pair( 'v', "1" ) );

    encodings.insert( std::make_pair( 'g', "2" ) );

    encodings.insert( std::make_pair( 'j', "2" ) );

    encodings.insert( std::make_pair( 'k', "2" ) );

    encodings.insert( std::make_pair( 'q', "2" ) );

    encodings.insert( std::make_pair( 's', "2" ) );

    encodings.insert( std::make_pair( 'x', "2" ) );

    encodings.insert( std::make_pair( 'z', "2" ) );

    encodings.insert( std::make_pair( 'd', "3" ) );

    encodings.insert( std::make_pair( 't', "3" ) );

    encodings.insert( std::make_pair( 'l', "4" ) );

    encodings.insert( std::make_pair( 'm', "5" ) );

    encodings.insert( std::make_pair( 'n', "5" ) );

    encodings.insert( std::make_pair( 'r', "6" ) );

    if( encodings[ letter ] == "" )
        return std::string(1, notDigit);

    return encodings[ letter ];

}

std::string Soundex::encodeDigits( const std::string& word ) const
{
    std::string encoding = "";

    for ( size_t i = 0 ; i < word.size() ; i++ )
    {
        if ( isComplete( encoding ) )
            break;

        char digit = word[ i ];

        if( digit != notDigit && encodeDigit( digit ) != lastDigit( encoding ) )
            encoding += encodeDigit( digit );
    }

    return encoding;
}

std::string Soundex::lastDigit( const std::string& encoding ) const
{
    if ( encoding.empty() )
        return std::string(1, notDigit);

    return std::string( 1, encoding[ encoding.size() -1 ] );
}

std::string Soundex::head( const std::string& word ) const
{
    return word.substr( 0, 1 );
}


std::string Soundex::tail( const std::string& word ) const
{
    return word.substr( 1 );
}

std::string Soundex::upperFront( const std::string& str ) const
{
    return std::string( 1
         , std::toupper( static_cast< unsigned char >( str[ 0 ] ) ) );
}
