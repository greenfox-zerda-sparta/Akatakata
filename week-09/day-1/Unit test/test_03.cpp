#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "03.cpp"

TEST_CASE("Fibonacci number") {
  Things thing;
  REQUIRE(thing.fibonacci_rec(4) == 3);
  REQUIRE(thing.fibonacci_rec(5) == 5);
}

TEST_CASE("Fibonacci number index: 0") {
  Things thing;
  REQUIRE(thing.fibonacci_rec(0) == 0);
}

TEST_CASE("Fibonacci number index: 1") {
  Things thing;
  REQUIRE(thing.fibonacci_rec(1) == 1);
}
