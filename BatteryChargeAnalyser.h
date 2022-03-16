#pragma once
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void swapIfGreater(unsigned int* Num1, unsigned int* Num2);
void TrimTheArray(unsigned int MaxVal, unsigned int* SortedArray, unsigned int* SizeOfCurrentArray);
void sortArrayAscending(unsigned int* CurrentArray, unsigned int* SortedArray, unsigned int SizeOfCurrentArray);
void getMinMaxConsecutiveOfGivenArray(unsigned int* MinVal, unsigned int* MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);
void getConsecutiveRangeFromArray(unsigned int* MinVal, unsigned int* MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);
unsigned int getNumberOfOccurencesFromRange(unsigned int MinVal, unsigned int MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);
void getstringFromValues(unsigned int MinVal, unsigned int MaxVal, unsigned int NumOfOccurence);

char* NumberOfReadingsInRange(unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);

static inline bool CheckWithinRange(unsigned int value, unsigned int MinVal, unsigned int MaxVal)
{
  bool WithinRange = false;
  if((value >= MinVal)&&(value <= MaxVal))
  {
    WithinRange = true;
  }
  
  return WithinRange;
}
