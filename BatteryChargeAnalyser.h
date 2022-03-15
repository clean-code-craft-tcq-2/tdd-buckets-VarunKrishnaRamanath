#pragma once
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

unsigned int getMaxConsecutiveOfGivenArray(unsigned int MinVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);
unsigned int getMinOfGivenArray(unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);
void getConsecutiveArray(unsigned int* ConsecutiveArray, unsigned int* SizeOfConsecutiveArray, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);
void getConsecutiveRangeFromArray(int* MinVal, int* MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);
unsigned int getNumberOfOccurencesFromRange(int MinVal, int MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);
void getstringFromValues(int MinVal, int MaxVal, unsigned int NumOfOccurence);

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
