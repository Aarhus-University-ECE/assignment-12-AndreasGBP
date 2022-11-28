#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.hpp"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 
TEST_CASE("Duration")
{
    duration d;
    REQUIRE(d.getduration() == 0);
    d = duration(10);
    REQUIRE(d.getduration() == 10);
    d = duration(21);
    REQUIRE(d.getduration() == 21);
    d.tick();
    REQUIRE(d.getduration() == 22);
    d.tick(5);
    REQUIRE(d.getduration() == 27);
    d.setalarm(30);
    REQUIRE(d.tick() == false);
    REQUIRE(d.tick(3) == true);
}
