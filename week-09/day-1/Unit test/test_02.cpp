#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "02.cpp"

TEST_CASE("Things: sum() adds elements of the vector: multiple elements") {
  Things sample_thing;
  sample_thing.integers.push_back(6);
  sample_thing.integers.push_back(8);
  sample_thing.integers.push_back(10);
  sample_thing.integers.push_back(12);
  REQUIRE(sample_thing.sum() == 36);
}

TEST_CASE("Things: sum() adds elements of the vector: empty vector") {
  Things sample_thing;
  sample_thing.integers.clear();
  REQUIRE(sample_thing.sum() == 0);
}

TEST_CASE("Things: sum() adds elements of the vector: one element") {
  Things sample_thing;
  sample_thing.integers.push_back(6);
  REQUIRE(sample_thing.sum() == sample_thing.integers[0]);
}