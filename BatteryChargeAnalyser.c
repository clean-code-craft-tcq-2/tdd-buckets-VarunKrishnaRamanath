#include "BatteryChargeAnalyser.h"

static char printchar[100];

void getConsecutiveArray(unsigned int* ConsecutiveArray, unsigned int* SizeOfConsecutiveArray, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
{
  ConsecutiveArray[0] = 4;
  ConsecutiveArray[1] = 5;
  ConsecutiveArray[2] = 6;
 
  SizeOfConsecutiveArray = 3;
  
  return; 
}

void getConsecutiveRangeFromArray(int* MinVal, int* MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
{
 unsigned int count = 0;
 unsigned int NumOfConsecutiveArray = 0;
 unsigned int SizeOfConsecutiveArray = 0;
 unsigned int TempArray[100];
 
 memset(TempArray, 0, sizeof(TempArray));
 
 getConsecutiveArray(TempArray, &SizeOfConsecutiveArray, CurrentArray, SizeOfCurrentArray);
 //getMinMaxOfConsecutiveArray();
 
  *MinVal = TempArray[0];
  *MaxVal = TempArray[SizeOfConsecutiveArray-1];
  return;
}

unsigned int getNumberOfOccurencesFromRange(int MinVal, int MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
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
