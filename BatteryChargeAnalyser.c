#include "BatteryChargeAnalyser.h"

static char printchar[100];

unsigned int getMinOfGivenArray(unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
{
  unsigned int count = 0;
  unsigned int MinVal = 0xffffffffu;
  for(count = 0; count < SizeOfCurrentArray; count++)
  {
    if(CurrentArray[count] < MinVal)
    {
     MinVal = CurrentArray[count]; 
    }
  }
  
  return MinVal;
}

unsigned int getMaxConsecutiveOfGivenArray(unsigned int MinVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
{
  return 6;
}

void getConsecutiveArray(unsigned int* ConsecutiveArray, unsigned int* SizeOfConsecutiveArray, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
{
  unsigned int count = 0;
  
  unsigned int MinVal = getMinOfGivenArray(CurrentArray, SizeOfCurrentArray);
  unsigned int MaxVal = getMaxConsecutiveOfGivenArray(MinVal, CurrentArray, SizeOfCurrentArray);
  
  for(count = MinVal; count <= MaxVal; count++)
  {
    ConsecutiveArray[count - MinVal] = count;
  }
 
  *SizeOfConsecutiveArray = MaxVal - MinVal + 1;
  
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
