#include <stdbool.h>
#include <string.h>

#define MAX_CURRENT_SENSED_BY_ADC             10  /* Amps */
#define MAX_NUMBER_OF_BITS_SUPPORTED_BY_ADC   12 /* Bits */
#define MIN_VALUE_READ_BY_ADC                 0
#define MAX_VALUE_READ_BY_ADC                 4095
#define ERROR_IN_ADC_READING                  4096


int ConvertAdcToAmp(unsigned int ADCValue, unsigned int CurrentInAmp);
