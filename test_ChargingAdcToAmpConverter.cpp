#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <string.h>
#include "ChargingAdcToAmpConverter.h"

unsigned int AmpValue = 0;
TEST_CASE("To check if ADC o/p 0 is read as 0A by the converter")
{
  REQUIRE(ConvertAdcToAmp(0, &AmpValue) == ADCToAmpConversionSucessful); /* function returns 0 indicating no error */
  REQUIRE(AmpValue == 0);
}

TEST_CASE("To check if ADC o/p 4094 is read as 10A by the converter")
{
  REQUIRE(ConvertAdcToAmp(4094, &AmpValue) == ADCToAmpConversionSucessful); /* function returns 0 indicating no error */
  REQUIRE(AmpValue == 10);
}

TEST_CASE("To check if ADC o/p 4095 or greater is read as error by the converter")
{
  REQUIRE(ConvertAdcToAmp(4095, &AmpValue) == ADCToAmpConversionNotSucessful); /* function returns 1 indicating error */
  REQUIRE(AmpValue == 10); /* retains previous value and function doesn't modify the value */
}

TEST_CASE("To check if ADC o/p 1146 is read as 3A by the converter")
{
  REQUIRE(ConvertAdcToAmp(1146, &AmpValue) == ADCToAmpConversionSucessful); /* function returns 0 indicating no error */
  REQUIRE(AmpValue == 3); 
}
