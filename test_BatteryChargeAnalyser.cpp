#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <string.h>
#include "BatteryChargeAnalyser.h"

//TEST_CASE("To give 4,5 as input and expect 4-5, 2 as output") 
{
  //unsigned int CurrentArray[] = {4,5};
  //REQUIRE(strcmp(NumberOfReadingsInRange(CurrentArray, 2), "4-5, 2\n"));
}

TEST_CASE("To give 4,5,6 as input and expect 4-6, 3 as output") 
{
  unsigned int CurrentArray[] = {4,5,6};
  REQUIRE(strcmp(NumberOfReadingsInRange(CurrentArray, 3), "4-6, 3\n"));
}
