#include "AdcToAmpConverter.h"

#define CONVERT_ADC_AMP(AdcValue)   ((float)((AdcParameterStruct.AdcConversionScale*(ADCValue))/(float)(AdcParameterStruct.MaxValueReadByAdc)) + (float)AdcParameterStruct.AdcConversionOffset)
#define IS_GREATER_THAN_MAX_VALUE(ADCValue)  (ADCValue > AdcParameterStruct.MaxValueReadByAdc)

static int RoundOffToNearestIntegerValue(float value)
{
  int IntegerVal = 0;
  float Precesiondifference = value - (int)value;

  if(fabs(Precesiondifference) <= 0.5)
  {
   IntegerVal = (int)value;
  }
  else
  {
      if(Precesiondifference > 0)
      {
          IntegerVal = (int)value + 1;
      }
      else
      {
          IntegerVal = (int)value - 1;
      }
  }
  return IntegerVal;
}

int ConvertAdcToAmp(int ADCValue, int* CurrentInAmp)
{
 int returnValue = ADCToAmpConversionNotSucessful;
 
 if(IS_GREATER_THAN_MAX_VALUE(ADCValue))
 {
  returnValue = ADCToAmpConversionNotSucessful;  
 }
 else
 {
  *CurrentInAmp = RoundOffToNearestIntegerValue(CONVERT_ADC_AMP(ADCValue));
   returnValue = ADCToAmpConversionSucessful;
 }
 
  return returnValue;
}

int ConvertAdcArrayToAmpArray(int* AdcArray, int* CurrentArrayInAmp, unsigned int sizeOfAdcArray)
{
  unsigned int arrayIndex = 0;
  int returnValue = 0;
  
  for(arrayIndex = 0;arrayIndex < sizeOfAdcArray;arrayIndex++)
  {
    returnValue |= ConvertAdcToAmp(AdcArray[arrayIndex], &CurrentArrayInAmp[arrayIndex]);
  }
  
  return returnValue;
}
