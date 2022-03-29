#include "ChargingAdcToAmpConverter.h"

#define CONVERT_ADC_TO_AMP(CurrentInAmp)  ((MAX_CURRENT_SENSED_BY_ADC*(*CurrentInAmp))/MAX_VALUE_READ_BY_ADC)

int ConvertAdcToAmp(unsigned int ADCValue, unsigned int* CurrentInAmp)
{
  *CurrentInAmp = CONVERT_ADC_TO_AMP(CurrentInAmp);
 
  return ADCToAmpConversionSucessful;
}
