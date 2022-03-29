#include "ChargingAdcToAmpConverter.h"

#define CONVERT_ADC_TO_AMP(ADCValue)  ((MAX_CURRENT_SENSED_BY_ADC*(ADCValue))/(float)MAX_VALUE_READ_BY_ADC)
#define IS_GREATER_THAN_MAX_VALUE(ADCValue)  (ADCValue > MAX_VALUE_READ_BY_ADC)

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

int ConvertAdcToAmp(unsigned int ADCValue, unsigned int* CurrentInAmp)
{
 int returnValue = ADCToAmpConversionNotSucessful;
 
 if(IS_GREATER_THAN_MAX_VALUE(ADCValue))
 {
  returnValue = ADCToAmpConversionNotSucessful;  
 }
 else
 {
  *CurrentInAmp = RoundOffToNearestIntegerValue(CONVERT_ADC_TO_AMP(ADCValue));
   returnValue = ADCToAmpConversionSucessful;
 }
 
  return returnValue;
}
