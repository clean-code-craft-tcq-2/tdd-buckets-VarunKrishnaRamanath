#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <string.h>
#include "ChargingAdcToAmpConverter.h"

unsigned int AmpValue = 0;
TEST_CASE("To check if ADC o/p 0 is read as 0 amp by the converter")
{
  REQUIRE(ConvertAdcToAmp(0, &AmpValue) == 0); /* function returns 0 indicating no error */
  REQUIRE(AmpValue == 0);
}

TEST_CASE("To check if ADC o/p 4095 is read as 10 amp by the converter")
{
  REQUIRE(ConvertAdcToAmp(4095, &AmpValue) == 0); /* function returns 0 indicating no error */
  REQUIRE(AmpValue == 10);
}

TEST_CASE("To check if ADC o/p 4096 or greater is read as error by the converter")
{
  REQUIRE(ConvertAdcToAmp(4096, &AmpValue) == 1); /* function returns 1 indicating error */
  REQUIRE(AmpValue == 10); /* retains previous value and function doesn't modify the value */
}
