#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "test_ADC.h"
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


TEST_CASE("To check if ADC o/p 0 is read as 0A by the converter")
{
  int AdcOutput = 0;
  int expectedCurrentInAmp = 0;
  validateAdcConverter_NoError(AdcOutput, expectedCurrentInAmp);
}

TEST_CASE("To check if ADC o/p 4094 is read as 10A by the converter")
{
  int AdcOutput = 4094;
  int expectedCurrentInAmp = 10;
  validateAdcConverter_NoError(AdcOutput, expectedCurrentInAmp);
}

TEST_CASE("To check if ADC o/p 4095 or greater is read as error by the converter")
{
  int AdcOutput = 4095;
  int expectedCurrentInAmp = 0;
  validateAdcConverter_NoError(AdcOutput, expectedCurrentInAmp);
}

TEST_CASE("To check if ADC o/p 1146 is read as 3A by the converter")
{
  int AdcOutput = 1146;
  int expectedCurrentInAmp = 3;
  validateAdcConverter_NoError(AdcOutput, expectedCurrentInAmp);
}

TEST_CASE("To supply array of ADC values to a function and get array of CurrentInAmp as output")
{
  int AdcArray[10] = {1146, 1646, 1770, 2500, 2300, 3000, 3400, 3500, 3700, 4000};
  int CurrentArrayInAmp[10];
  int expected_CurrentArrayInAmp[10] = {3, 4, 4, 6, 6, 7, 8, 9, 9, 10};
  unsigned int sizeOfAdcArray = sizeof(AdcArray)/sizeof(int);
  
  CheckCurrentArrayWithAdcInput(AdcArray, expected_CurrentArrayInAmp, sizeOfAdcArray);

}

TEST_CASE("After integration of BatteryChargeAnalyser, pass array of ADC values and expect the ranges as output")
{
  int AdcArray[10] = {1146, 1646, 1770, 2500, 2300, 3000, 3400, 3500, 3700, 4000};
  int CurrentArrayInAmp[10];
  unsigned int sizeOfAdcArray = sizeof(AdcArray)/sizeof(int);
  
  CheckRangesWithAdcInput(AdcArray,"3-4, 3\n6-10, 7\n",sizeOfAdcArray);
}
