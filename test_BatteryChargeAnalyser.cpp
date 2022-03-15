#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <string.h>
#include "BatteryChargeAnalyser.h"
#include <stdio.h>

#define SIZEOFARRAY(a)  (sizeof(a)/sizeof(unsigned int))

TEST_CASE("To give 4,5 as input and expect 4-5, 2 as output") 
{
  unsigned int CurrentArray[] = {4,5};
  REQUIRE(strcmp(NumberOfReadingsInRange(CurrentArray, 2), "4-5, 2\n"));
}

TEST_CASE("To give 4,5,6 as input and expect 4-6, 3 as output") 
{
  unsigned int CurrentArray[] = {4,5,6};
  REQUIRE(strcmp(NumberOfReadingsInRange(CurrentArray, 3), "4-6, 3") == 0);
  
  int MinVal, MaxVal = 0;
  getConsecutiveRangeFromArray(&MinVal, &MaxVal, CurrentArray, 3);
  REQUIRE(MinVal == 4);
  REQUIRE(MaxVal == 6);
  
  unsigned int TempArray2[3] = {4, 5, 6};
  REQUIRE(getMinOfGivenArray(TempArray2, SIZEOFARRAY(TempArray2)) == 4);
  REQUIRE(getMaxConsecutiveOfGivenArray(getMinOfGivenArray(TempArray2, SIZEOFARRAY(TempArray2)), TempArray2, SIZEOFARRAY(TempArray2)) == 6);
  
  REQUIRE(CheckWithinRange(5,4,6) == true);
}

TEST_CASE("To give 4,5,6,6,7 as input and expect 4-7, 5 as output") //input in ascending order
{
  unsigned int CurrentArray[] = {4,5,6,6,7};
  REQUIRE(strcmp(NumberOfReadingsInRange(CurrentArray, SIZEOFARRAY(CurrentArray)), "4-7, 5") == 0);
}

TEST_CASE("To give 6,7,6,5,4 as input and expect 4-7, 5 as output") // input shuffled
{
  unsigned int CurrentArray[] = {6,7,6,5,4};
  unsigned int SortedArray[5];
  unsigned int expectedSortedArray[5] = {4,5,6,6,7};
  unsigned int Num1 = 4;
  unsigned int Num2 = 3;
  
  swapIfGreater(&Num1, &Num2);
  REQUIRE(Num1 == 3);
  REQUIRE(Num2 == 4);
  
  sortArrayAscending(CurrentArray,SortedArray,SIZEOFARRAY(expectedSortedArray));
   REQUIRE(memcmp(SortedArray,expectedSortedArray,SIZEOFARRAY(expectedSortedArray)) == 1);
   
   REQUIRE(strcmp(NumberOfReadingsInRange(CurrentArray, SIZEOFARRAY(CurrentArray)), "4-7, 5") == 0);
}

TEST_CASE("To give array of non consecutive numbers and expect error output") // non consecutive data present
{
  unsigned int CurrentArray[] = {1,3,5,7,9};
  REQUIRE(strstr(NumberOfReadingsInRange(CurrentArray, SIZEOFARRAY(CurrentArray)), "Error"));
}

TEST_CASE("To give 7,5,4,6,7,9 as input and expect 4-7, 5 as output") // non consecutive data laong with consecutive array in input
{
  unsigned int CurrentArray[] = {7,5,4,6,7,9};
  REQUIRE(strcmp(NumberOfReadingsInRange(CurrentArray, SIZEOFARRAY(CurrentArray)), "4-7, 5") == 0);
}
/*
TEST_CASE("To give 4,5,6,6,8,9,10 as input and expect 4-6, 4 and 8-10, 3 as output") // two consecutive array in input
{
  unsigned int CurrentArray[] = {4,5,6,6,8,9,10};
  printf("%s",NumberOfReadingsInRange(CurrentArray, SIZEOFARRAY(CurrentArray)));
  REQUIRE(strcmp(NumberOfReadingsInRange(CurrentArray, SIZEOFARRAY(CurrentArray)), "4-6, 4\n8-10,3") == 0);
}*/
