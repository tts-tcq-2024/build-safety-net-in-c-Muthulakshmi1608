#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
 char soundex[5];
  generateSoundex("Robert", soundex);
  generateSoundex("Rubin", soundex);
  //ASSERT_EQ(soundex,"R163");
}

