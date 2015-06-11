#include "gmock/gmock.h"
#include "Soundex.h"


class SoundexEncoding: public testing::Test {
public:
    Soundex soundex;
};


TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {

    ASSERT_THAT(soundex.encode("A"), testing::Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {

    ASSERT_THAT(soundex.encode("I"), testing::Eq("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits) {

    EXPECT_THAT(soundex.encode("Ax"), testing::Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
    ASSERT_THAT(soundex.encode("A#"), testing::Eq("A000"));
}
