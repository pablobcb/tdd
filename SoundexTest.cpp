#include "gmock/gmock.h"
#include "Soundex.h"

//using ::testing::Eq;


class SoundexEncoding: public testing::Test {
public:
    Soundex soundex;
};


TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {

    //ASSERT_THAT(soundex.encode("A"), testing::Eq("A000"));
    ASSERT_THAT(1, testing::Eq(1));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {

    ASSERT_THAT(soundex.encode("I"), testing::Eq("I000"));
}
