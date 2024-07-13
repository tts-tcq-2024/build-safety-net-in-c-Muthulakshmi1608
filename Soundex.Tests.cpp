#include <gtest/gtest.h>
#include "Soundex.h"

char soundex[5];

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
 
 generateSoundex("Robert", soundex);
 generateSoundex("Honeyman", soundex);
 generateSoundex("Tymczak", soundex);
 generateSoundex("Pfister", soundex);
 generateSoundex("Rubin", soundex);
 
  //ASSERT_EQ(soundex,"R163");
}

TEST(SoudexTestsuite, SameCodeWithAppropriateDigits) {
generateSoundex("Ashcroft", soundex);
generateSoundex("Rupert", soundex);
}
TEST(SoudexTestsuite, VowelsWithAppropriateDigits) { 
 generateSoundex("Ashcraft", soundex);
 generateSoundex("Honeyman", soundex);
}
 
