#pragma once
#include <stdbool.h>
#include <string.h>
#include <float.h>

#define ADCToAmpConversionSucessful      0
#define ADCToAmpConversionNotSucessful   1

typedef struct{
  int MinCurrentSensedByAdc;
  int MaxCurrentSensedByAdc;
  int AdcConversionScale;
  int AdcConversionOffset;
  int MaxValueReadByAdc;
}AdcParameters;

#include <math.h>

static inline int GetAbsoluteValue(int value)
{
 return abs(value); 
}

static inline void GetAbsoluteValuesFromArray(int* Array, int* AbsArray, unsigned int sizeOfArray)
{
  unsigned int loop = 0;
  
  for(loop = 0; loop < sizeOfArray; loop++)
  {
    AbsArray[loop] = abs(Array[loop]);
  }
  
 return; 
}

extern const AdcParameters AdcParameterStruct;

int ConvertAdcToAmp(int ADCValue, int* CurrentInAmp);
int ConvertAdcArrayToAmpArray(int* AdcArray, int* CurrentArrayInAmp, unsigned int sizeOfAdcArray);
