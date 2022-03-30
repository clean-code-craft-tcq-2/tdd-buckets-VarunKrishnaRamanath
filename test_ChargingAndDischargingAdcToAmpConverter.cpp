#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "test_ADC.h"
#include <string.h>
#include "AdcToAmpConverter.h"
#include "BatteryChargeAnalyser.h"

const AdcParameters AdcParameterStruct = {
  -15,      // MinCurrentSensedByAdc in Amp
  15,     // MaxCurrentSensedByAdc in Amp
  30,     // AdcConversionScale -> Since this is dual direction, 2*maxCurrentSensedByAdc is considered as scale
  -15,      // AdcConversionOffset
  1022    // MaxValueReadByAdc
};

int AmpValue = 0;
TEST_CASE("To check if ADC o/p 0 is read as -15A by the converter")
{
  int AdcOutput = 0;
  int expectedCurrentInAmp = -15;
  validateAdcConverter_NoError(AdcOutput, expectedCurrentInAmp);
}

TEST_CASE("To check if ADC o/p 1022 is read as 15A by the converter")
{
  int AdcOutput = 1022;
  int expectedCurrentInAmp = 15;
  validateAdcConverter_NoError(AdcOutput, expectedCurrentInAmp);
}

TEST_CASE("To check if ADC o/p 1023 or greater is read as error by the converter")
{
  int AdcOutput = 1023;
  int expectedCurrentInAmp = 0;
  validateAdcConverter_Error(AdcOutput, expectedCurrentInAmp);
}

TEST_CASE("To check if ADC o/p 511 is read as 0A by the converter")
{
  int AdcOutput = 511;
  int expectedCurrentInAmp = 0;
  validateAdcConverter_NoError(AdcOutput, expectedCurrentInAmp);
}

TEST_CASE(" To provide array of ADC values as input and expect array of current values as output")
{
  int AdcArray[10] = {414,404,660,680,345,280,780,800,210,200};
  int expected_CurrentArrayInAmp[10] = {-3,-3,4,5,-5-7,8,8,-9,-9};
  unsigned int sizeOfAdcArray = sizeof(AdcArray)/sizeof(int);
  
  CheckCurrentArrayWithAdcInput(AdcArray, expected_CurrentArrayInAmp, sizeOfAdcArray);
}

TEST_CASE("After integration of BatteryChargeAnalyser, pass array of ADC values and expect the ranges as output")
{
  int AdcArray[10] = {414,404,660,680,345,280,780,800,210,200};
  int expected_CurrentArrayInAmp[10] = {-3,-3,4,5,-5-7,8,8,-9,-9};
  char CurrentRange[100] = "3-5, 5\n7-9, 5\n";
  unsigned int sizeOfAdcArray = sizeof(AdcArray)/sizeof(int);
  
  CheckCurrentArrayWithDischargingAdcInput(AdcArray, expected_CurrentArrayInAmp, sizeOfAdcArray);
}
