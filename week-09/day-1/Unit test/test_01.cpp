#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "01.cpp"

TEST_CASE("Apples: getApple() returns apples") {
  Apple apple;
  REQUIRE(apple.getApple() == "apple");
}