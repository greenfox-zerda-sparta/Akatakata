#define TEST
#ifdef TEST
//#include "test_thetesting.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "WordToolBox.h"

TEST_CASE("countHowMany: count characters in Tarzan's toenails") {
  WordToolBox wSource("Tarzan's toenails");
  REQUIRE(wSource.countHowMany('a') == 3);
  REQUIRE(wSource.countHowMany('T') == 2);
  REQUIRE(wSource.countHowMany('x') == 0);
}

TEST_CASE("setStringHeld") {
  WordToolBox text("Tarzan's toenails");
  text.setStringHeld("Me Tarzan, You Jane");
  REQUIRE(text.getStringHeld() == "Me Tarzan, You Jane");
}
#endif

// #define PRODUCTION
#ifdef PRODUCTION
#include <iostream>
using namespace std;
#include "WordToolBox.h"
int main() {
  WordToolBox wSource("Tarzan's toenails");
  cout << "countHowMany(\"a\")=" << wSource.countHowMany('a') << endl; // countHowMany("a")=3
  cout << "countHowMany(\"T\")=" << wSource.countHowMany('T') << endl; // countHowMany("T")=2
  cout << "countHowMany(\"t\")=" << wSource.countHowMany('t') << endl; // countHowMany("t")=2
  cout << "countHowMany(\"x\")=" << wSource.countHowMany('x') << endl; // countHowMany("x")=0
  cout << "countHowMany(\" \")=" << wSource.countHowMany(' ') << endl; // countHowMany(" ")=1
  return 0;
}

#endif