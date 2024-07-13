#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
 char soundex[5];
 generateSoundex("Robert", soundex);
 generateSoundex("Rubin", soundex);
 generateSoundex("Honeyman", soundex);
 generateSoundex("Rupert", soundex);
 generateSoundex("Ashcraft", soundex);
 generateSoundex("Tymczak", soundex);
 generateSoundex("Pfister", soundex);

  //ASSERT_EQ(soundex,"R163");
}

