#pragma once
#include <string.h>
#include <stdio.h>

void getConsecutiveRangeFromArray(int* MinVal, int* MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);
unsigned int getNumberOfOccurencesFromRange(int MinVal, int MaxVal, unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);
void getstringFromValues(int MinVal, int MaxVal, unsigned int NumOfOccurence);

char* NumberOfReadingsInRange(unsigned int* CurrentArray, unsigned int SizeOfCurrentArray);
