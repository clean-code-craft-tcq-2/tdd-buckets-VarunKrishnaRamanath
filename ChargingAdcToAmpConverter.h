#pragma once
#include <stdbool.h>
#include <string.h>

#define ADCToAmpConversionSucessful      0
#define ADCToAmpConversionNotSucessful   1

typedef struct{
  int MinCurrentSensedByAdc;
  int MaxCurrentSensedByAdc;
  int AdcConversionScale;
  int AdcConversionOffset;
  int MaxValueReadByAdc;
}AdcParameters;

extern const AdcParameters AdcParameterStruct;

int ConvertAdcToAmp(int ADCValue, int* CurrentInAmp);
int ConvertAdcArrayToAmpArray(int* AdcArray, int* CurrentArrayInAmp, unsigned int sizeOfAdcArray);
