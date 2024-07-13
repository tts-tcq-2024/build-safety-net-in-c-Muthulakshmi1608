#include <gtest/gtest.h>
#include "Soundex.h"

char soundex[5];

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
 
 generateSoundex("Robert", soundex);
 generateSoundex("Honeyman", soundex);
 generateSoundex("Rupert", soundex);
 generateSoundex("Ashcraft", soundex);
 generateSoundex("Tymczak", soundex);
 generateSoundex("Pfister", soundex);

  //ASSERT_EQ(soundex,"R163");
}

TEST_1(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
generateSoundex("Rubin", soundex);
}
