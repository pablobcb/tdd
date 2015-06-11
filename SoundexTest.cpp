#include "gmock/gmock.h"
#include <string>

class Soundex {

public:
  std::string encode(const std::string& word) const
  {
    return "";
  }
};


TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
  Soundex soundex;

  std::string encoded = soundex.encode("A");

  printf("%s\n", encoded.c_str());

  ASSERT_THAT(encoded, testing::Eq("A"));
}