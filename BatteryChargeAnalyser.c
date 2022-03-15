#include "BatteryChargeAnalyser.h"

static char printchar[100];

void sortArrayAscending(unsigned int* CurrentArray, unsigned int* SortedArray, unsigned int SizeOfCurrentArray)
{
  
}

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
   unsigned int count = 0;
   unsigned int MaxConsecutiveValue = MinVal;
  
  //assume that array is sorted
   for(count = 0; count < SizeOfCurrentArray; count++)
   {
     if(MaxConsecutiveValue + 1 == CurrentArray[count])
     {
       MaxConsecutiveValue = CurrentArray[count];
     }
   }
  
  return MaxConsecutiveValue;
}

void getConsecutiveRangeFromArray(int* MinVal, int* MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
{
 unsigned int count = 0;
 unsigned int NumOfConsecutiveArray = 0;
 unsigned int SizeOfConsecutiveArray = 0;
 unsigned int TempArray[100];
 
 memset(TempArray, 0, sizeof(TempArray));
 
 *MinVal = getMinOfGivenArray(CurrentArray, SizeOfCurrentArray);
 *MaxVal = getMaxConsecutiveOfGivenArray(*MinVal, CurrentArray, SizeOfCurrentArray);
  
  return;
}

unsigned int getNumberOfOccurencesFromRange(int MinVal, int MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
{
  unsigned int count = 0;
  unsigned int NumofOccurences = 0;
  
  for(count = 0; count < SizeOfCurrentArray; count++)
  {
    if(CheckWithinRange(CurrentArray[count], MinVal, MaxVal))
    {
      NumofOccurences++;
    }
  }
  return NumofOccurences; 
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
  if(MinVal == MaxVal)
  {
    strcpy(printchar, "Error!! This array doesn't have any consecutive numbers");
  }
  else
  {
    NumOfOccurence = getNumberOfOccurencesFromRange(MinVal, MaxVal, CurrentArray, SizeOfCurrentArray);
    getstringFromValues(MinVal, MaxVal, NumOfOccurence);
  }
  
  return printchar;
}
