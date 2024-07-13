#include <gtest/gtest.h>
#include "Soundex.h"
 char soundex[5];
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  generateSoundex("Robert", soundex);
  //ASSERT_EQ(soundex,"R163");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  //char soundex[5];
  generateSoundex("Rubin", soundex);
  //ASSERT_EQ(soundex,"R150");
}
