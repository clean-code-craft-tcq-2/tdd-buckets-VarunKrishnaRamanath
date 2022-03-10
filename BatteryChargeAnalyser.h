#pragma once
#include <string.h>

void getConsecutiveRangeFromArray(int* MinVal, int* MaxVal, unsigned int* CurrentArray);
unsigned int getNumberOfOccurencesFromRange(int MinVal, int MaxVal, unsigned int* CurrentArray);
void getstringFromValues(int MinVal, int MaxVal, unsigned int NumOfOccurence);

char* NumberOfReadingsInRange(unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);
