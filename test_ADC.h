#include "ChargingAdcToAmpConverter.h"
#include "BatteryChargeAnalyser.h"

static inline void validateAdcConverter_NoError(int AdcOutput, int ExpectedCurrentInAmp)
{
  int CurrentInAmp = 0;
  
  REQUIRE(ConvertAdcToAmp(AdcOutput, &CurrentInAmp) == ADCToAmpConversionSucessful); /* function returns 0 indicating no error */
  REQUIRE(CurrentInAmp == ExpectedCurrentInAmp);
}

static inline void validateAdcConverter_Error(int AdcOutput, int ExpectedCurrentInAmp)
{
  int CurrentInAmp = 0;
  
  REQUIRE(ConvertAdcToAmp(AdcOutput, &CurrentInAmp) == ADCToAmpConversionNotSucessful); /* function returns 1 indicating error */
  REQUIRE(CurrentInAmp == ExpectedCurrentInAmp);
}

static inline void CheckCurrentArrayWithAdcInput(int* AdcOutputArray, int* ExpectedCurrentArray, unsigned int sizeOfAdcArray)
{
  int CurrentArrayInAmp[sizeOfAdcArray];
  
  /* First convert adc to amp */
  REQUIRE(ConvertAdcArrayToAmpArray(AdcOutputArray, CurrentArrayInAmp, sizeOfAdcArray) == ADCToAmpConversionSucessful); /* function returns 0 indicating no error */
  /* Pass the array in amp to range detection function */
  REQUIRE(memcmp(CurrentArrayInAmp, ExpectedCurrentArray, sizeOfAdcArray) == 0);
}

static inline void CheckRangesWithAdcInput(int* AdcOutputArray, char* ExpectedCurrentArrayRange, unsigned int sizeOfAdcArray)
{
  int CurrentArrayInAmp[sizeOfAdcArray];
  
  /* First convert adc to amp */
  REQUIRE(ConvertAdcArrayToAmpArray(AdcOutputArray, CurrentArrayInAmp, sizeOfAdcArray) == ADCToAmpConversionSucessful); /* function returns 0 indicating no error */
  /* Pass the array in amp to range detection function */
  REQUIRE(strcmp(NumberOfReadingsInRange((unsigned int*)CurrentArrayInAmp, sizeOfAdcArray), ExpectedCurrentArrayRange) == 0);
}
