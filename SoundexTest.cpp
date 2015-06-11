#include "gmock/gmock.h"
#include <string>

//using ::testing::Eq;

class Soundex {

public:
  std::string encode(const std::string& word) const
  {
    return padWithZero(word);
  }

private:
  std::string padWithZero(const std::string& word ) const
  {
    return word + "000";
  }
};


TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
  Soundex soundex;

  std::string encoded = soundex.encode("A");

  ASSERT_THAT(encoded, testing::Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
  Soundex soundex;

  std::string encoded = soundex.encode("I");

  ASSERT_THAT(encoded, testing::Eq("I000"));
}