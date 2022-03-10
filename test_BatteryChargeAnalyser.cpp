#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <cstring.h>
#include "BatteryChargeAnalyser.h"

uint8 CurrentArray[100] = {4,5};

TEST_CASE("To give 4,5 as input and expect 4-5, 2 as output") 
{
  REQUIRE(strcmp(NumberOfReadingsInRange(uint8* CurrentArray, uint8 SizeOfCurrentArray)(CurrentArray, 2), "4-5, 2"));
}
