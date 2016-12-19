#ifdef TEST
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "WordToolBox.h"

TEST_CASE("countHowMany: count characters in Tarzan's toenails") {
  WordToolBox wSource();
  REQUIRE(wSource.countHowMany('a') == 3);
  REQUIRE(wSource.countHowMany('T') == 2);
  REQUIRE(wSource.countHowMany('x') == 0);
}

TEST_CASE("setStringHeld") {
  WordToolBox text("Tarzan's toenails");
  text.setStringHeld("Me Tarzan, You Jane");
  REQUIRE(text.getStringHeld == "Me Tarzan, You Jane")
}



#endif