#include "BatteryChargeAnalyser.h"

static char printchar[100];

void getConsecutiveRangeFromArray(int* MinVal, int* MaxVal, unsigned int* CurrentArray)
{
  *MinVal = 4;
  *MaxVal = 6;
  return;
}

unsigned int getNumberOfOccurencesFromRange(int MinVal, int MaxVal, unsigned int* CurrentArray)
{
  return 3; 
}

void getstringFromValues(int MinVal, int MaxVal, unsigned int NumOfOccurence)
{
  sprintf(printchar, "%d-%d, %d", MinVal, MaxVal, NumOfOccurence);
}

char* NumberOfReadingsInRange(unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
{
  int MinVal, MaxVal = 0;
  unsigned int NumOfOccurence = 0;
  
  getConsecutiveRangeFromArray(&MinVal, &MaxVal, CurrentArray, SizeOfCurrentArray);
  NumOfOccurence = getNumberOfOccurencesFromRange(MinVal, MaxVal, CurrentArray, SizeOfCurrentArray);
  getstringFromValues(MinVal, MaxVal, NumOfOccurence);
  
  return printchar;
}
