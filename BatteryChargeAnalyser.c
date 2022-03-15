#include "BatteryChargeAnalyser.h"

static char printchar[100];

void swapIfGreater(unsigned int* Num1, unsigned int* Num2)
{
  unsigned int TempVar = 0;
  
  if(*Num1 > *Num2)
   {
     TempVar = *Num1;
     *Num1 = *Num2;
     *Num2 = TempVar;
   }
}

void sortArrayAscending(unsigned int* CurrentArray, unsigned int* SortedArray, unsigned int SizeOfCurrentArray)
{
  unsigned int SortSize = SizeOfCurrentArray;
  unsigned int count = 0;
  
  memcpy(SortedArray, CurrentArray, (SizeOfCurrentArray*sizeof(unsigned int)));
  
  while(SortSize>1)
  {
     for(count = 0; count < SortSize-1; count++)
     {
       swapIfGreater(&SortedArray[count], &SortedArray[count+1]);
     }
     SortSize--;
  }
}

void getMinMaxConsecutiveOfGivenArray(unsigned int* MinVal, unsigned int* MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
{
   unsigned int count = 0;
   *MaxVal = CurrentArray[0];
   *MinVal = CurrentArray[0];
  
  //assume that array is sorted
   for(count = 0; count < (SizeOfCurrentArray - 1); count++)
   {
     if(*MaxVal + 1 == CurrentArray[count+1])
     {
       *MaxVal = CurrentArray[count+1];
     }
     else if(*MaxVal == *MinVal)
     {
         *MaxVal = CurrentArray[count+1];
         *MinVal = *MaxVal;
     }
     else
     {
         
     }
     
   }
  
  return;
}

void getConsecutiveRangeFromArray(unsigned int* MinVal, unsigned int* MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
{
 unsigned int count = 0;
 unsigned int NumOfConsecutiveArray = 0;
 unsigned int SizeOfConsecutiveArray = 0;
 unsigned int TempArray[100];
 
 memset(TempArray, 0, sizeof(TempArray));
 
 getMinMaxConsecutiveOfGivenArray(MinVal, MaxVal, CurrentArray, SizeOfCurrentArray);
  
  return;
}

unsigned int getNumberOfOccurencesFromRange(unsigned int MinVal, unsigned int MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
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

void getstringFromValues(unsigned int MinVal, unsigned int MaxVal, unsigned int NumOfOccurence)
{
  sprintf(printchar, "%d-%d, %d", MinVal, MaxVal, NumOfOccurence);
}

char* NumberOfReadingsInRange(unsigned int* CurrentArray, unsigned int SizeOfCurrentArray)
{
  unsigned int MinVal, MaxVal = 0;
  unsigned int NumOfOccurence = 0;
  unsigned int SortedArray[100];
  
  sortArrayAscending(CurrentArray, SortedArray, SizeOfCurrentArray);
  getConsecutiveRangeFromArray(&MinVal, &MaxVal, SortedArray, SizeOfCurrentArray);
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
