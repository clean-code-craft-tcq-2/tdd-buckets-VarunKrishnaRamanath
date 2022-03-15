#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <string.h>
#include "BatteryChargeAnalyser.h"

//TEST_CASE("To give 4,5 as input and expect 4-5, 2 as output") 
//{
  //unsigned int CurrentArray[] = {4,5};
  //REQUIRE(strcmp(NumberOfReadingsInRange(CurrentArray, 2), "4-5, 2\n"));
//}

TEST_CASE("To give 4,5,6 as input and expect 4-6, 3 as output") 
{
  unsigned int CurrentArray[] = {4,5,6};
  REQUIRE(strcmp(NumberOfReadingsInRange(CurrentArray, 3), "4-6, 3\n"));
  
  int MinVal, MaxVal = 0;
  getConsecutiveRangeFromArray(&MinVal, &MaxVal, CurrentArray, 3);
  REQUIRE(MinVal == 4);
  REQUIRE(MaxVal == 6);
  
  unsigned int TempArray2[3] = {4, 5, 6};
  REQUIRE(getMinOfGivenArray(TempArray2, 3) == 4);
  REQUIRE(getMaxConsecutiveOfGivenArray(getMinOfGivenArray(TempArray2, 3), TempArray2, 3) == 6);
  
  REQUIRE(CheckWithinRange(5,4,6) == true)
}

TEST_CASE("To give 4,5,6,6,7 as input and expect 4-7, 5 as output") 
{
  unsigned int CurrentArray[] = {4,5,6,6,7};
  REQUIRE(strcmp(NumberOfReadingsInRange(CurrentArray, 5), "4-7, 5\n"));
}

TEST_CASE("To give array of non consecutive numbers and expect error output")
{
  unsigned int CurrentArray[] = {1,3,5,7,9};
  REQUIRE(strstr(NumberOfReadingsInRange(CurrentArray, 5), "Error"));
}
