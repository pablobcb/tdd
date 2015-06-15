#include "gmock/gmock.h"
#include "Soundex.h"


class SoundexEncoding: public testing::Test
{
    public:
        Soundex soundex;
};


TEST_F( SoundexEncoding, RetainsSoleLetterOfOneLetterWord )
{
    ASSERT_THAT( soundex.encode( "A" ), testing::Eq( "A000" ) );
}


TEST_F( SoundexEncoding, PadsWithZerosToEnsureThreeDigits )
{
    ASSERT_THAT( soundex.encode( "I" ), testing::Eq( "I000" ) );
}


TEST_F( SoundexEncoding, ReplaceConsonantsWithAppropriateDigits )
{
    //TODO: why not test it all consonants?
    ASSERT_THAT( soundex.encode( "Ax" ), testing::Eq( "A200" ) );
}


TEST_F( SoundexEncoding, IgnoresNonAlphabetics )
{
    ASSERT_THAT( soundex.encode( "A#" ), testing::Eq( "A000" ) );
}


TEST_F( SoundexEncoding, ReplacesMultipleConsonantsWithDigits )
{
    ASSERT_THAT( soundex.encode( "Acdl" ), testing::Eq( "A234" ) );
}


TEST_F(SoundexEncoding, LimitsLengthToFourCharacters)
{
    ASSERT_THAT( soundex.encode( "Dcdlb" ).length(), testing::Eq( 4u ) );
}


TEST_F( SoundexEncoding, CombinesDuplicateEncodings )
{
    ASSERT_THAT( soundex.encodeDigit( 'b' ), testing::Eq( soundex.encodeDigit( 'f' ) ) );
    
    ASSERT_THAT( soundex.encodeDigit( 'c' ), testing::Eq( soundex.encodeDigit( 'g' ) ) );
    
    ASSERT_THAT( soundex.encodeDigit( 'd' ), testing::Eq( soundex.encodeDigit( 't' ) ) );

    ASSERT_THAT( soundex.encode( "Abfcgdt" ), testing::Eq( "A123") );
}

TEST_F( SoundexEncoding, UppercasesFirstLetter ) {
    ASSERT_THAT( soundex.encode( "abcd" ), testing::StartsWith( "A" ) );
}


TEST_F( SoundexEncoding, IgnoresVowelLikeLetters ) {
    ASSERT_THAT( soundex.encode( "BaAeEiIoOuUhHyYcdl" ), testing::Eq( "B234" ) );
}
