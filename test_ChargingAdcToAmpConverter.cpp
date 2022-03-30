#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <string.h>
#include "ChargingAdcToAmpConverter.h"
#include "BatteryChargeAnalyser.h"

const AdcParameters AdcParameterStruct = {
  0,      // MinCurrentSensedByAdc in Amp
  10,     // MaxCurrentSensedByAdc in Amp
  10,     // AdcConversionScale -> Since this is single direction, maxCurrentSensedByAdc is considered as scale
  0,      // AdcConversionOffset
  4094    // MaxValueReadByAdc
};

int AmpValue = 0;
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

TEST_CASE("To supply array of ADC values to a function and get array of CurrentInAmp as output")
{
  int AdcArray[10] = {1146, 1646, 1770, 2500, 2300, 3000, 3400, 3500, 3700, 4000};
  int CurrentArrayInAmp[10];
  int expected_CurrentArrayInAmp[10] = {3, 4, 4, 6, 6, 7, 8, 9, 9, 10};
  unsigned int sizeOfAdcArray = sizeof(AdcArray)/sizeof(int);
  
  REQUIRE(ConvertAdcArrayToAmpArray(AdcArray, CurrentArrayInAmp, sizeOfAdcArray) == 0); /* function returns 0 indicating no error */
  REQUIRE(memcmp(CurrentArrayInAmp, expected_CurrentArrayInAmp, sizeOfAdcArray) == 0); /* converted array matches with expected values */
}

TEST_CASE("After integration of BatteryChargeAnalyser, pass array of ADC values and expect the ranges as output")
{
  int AdcArray[10] = {1146, 1646, 1770, 2500, 2300, 3000, 3400, 3500, 3700, 4000};
  int CurrentArrayInAmp[10];
  unsigned int sizeOfAdcArray = sizeof(AdcArray)/sizeof(int);
  char CurrentRange[1000];
  
  /* First convert adc to amp */
  REQUIRE(ConvertAdcArrayToAmpArray(AdcArray, CurrentArrayInAmp, sizeOfAdcArray) == 0); /* function returns 0 indicating no error */
  /* Pass the array in amp to range detection function */
  REQUIRE(strcmp(NumberOfReadingsInRange((unsigned int*)CurrentArrayInAmp, sizeOfAdcArray), "3-4, 3\n6-10, 7\n") == 0);
}
