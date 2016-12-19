#ifdef TEST
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "WordToolBox.h"

TEST_CASE("countHowMany: count characters in Tarzan's toenails") {
  WordToolBox wSource("Tarzan's toenails");
  REQUIRE(wSource.countHowMany('a') == 3);
  REQUIRE(wSource.countHowMany('T') == 2);
  REQUIRE(wSource.countHowMany('x') == 0);
}

TEST_CASE("getStringHeld") {
  WordToolBox w("Tarzan");
  REQUIRE(w.getStringHeld() == "Tarzan");
}

TEST_CASE("setStringHeld") {
  WordToolBox text("Tarzan's toenails");
  text.setStringHeld("Me Tarzan, You Jane");
  REQUIRE(text.getStringHeld() == "Me Tarzan, You Jane");
}

TEST_CASE("isAnnagram: aloft") {
  WordToolBox w("aloft");
  REQUIRE(w.isAnnagram("falsetto") == false);
  REQUIRE(w.isAnnagram("float") == true);
  REQUIRE(w.isAnnagram("") == false);
}

TEST_CASE("isAnnagram: empty stringHeld") {
  WordToolBox w("");
  REQUIRE(w.isAnnagram("float") == false);
  REQUIRE(w.isAnnagram("") == true);
}
#endif