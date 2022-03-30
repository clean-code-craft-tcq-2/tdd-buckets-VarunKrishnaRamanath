#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
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
  validateAdcConverter_NoError(AdcOutput, expectedCurrentInAmp);
}

TEST_CASE("To check if ADC o/p 511 is read as 0A by the converter")
{
  int AdcOutput = 511;
  int expectedCurrentInAmp = 0;
  validateAdcConverter_NoError(AdcOutput, expectedCurrentInAmp);
}
