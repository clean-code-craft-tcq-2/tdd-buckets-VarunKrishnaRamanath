#include "ChargingAdcToAmpConverter.h"

#define CONVERT_ADC_AMP(AdcValue)   ((float)((AdcParameterStruct.AdcConversionScale*(ADCValue))/(float)(AdcParameterStruct.MaxValueReadByAdc)) + (float)AdcParameterStruct.AdcConversionOffset)
#define IS_GREATER_THAN_MAX_VALUE(ADCValue)  (ADCValue > AdcParameterStruct.MaxValueReadByAdc)

static int RoundOffToNearestIntegerValue(float value)
{
  int IntegerVal = 0;
  if((value - (int)value) <= 0.5)
  {
   IntegerVal = (int)value;
  }
  else
  {
   IntegerVal = (int)value + 1;
  }
  return IntegerVal;
}

int ConvertAdcToAmp(unsigned int ADCValue, int* CurrentInAmp)
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
    returnValue |= ConvertAdcToAmp((unsigned int)AdcArray[arrayIndex], &CurrentArrayInAmp[arrayIndex]);
  }
  
  return returnValue;
}
