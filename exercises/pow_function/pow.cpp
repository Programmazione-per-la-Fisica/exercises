#include <cassert>
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

int pow(int base, int exponent) {
  // Make sure that the exponent is non negative
  assert(exponent >= 0);

  int result{1};
  for (int i{}; i < exponent; ++i) {
    result *= base;
  }
  return result;
}

TEST_CASE("Testing the pow function") {
  CHECK(pow(2, 3) == 8);
  CHECK(pow(2, 1) == 2);
  CHECK(pow(2, 0) == 1);
  CHECK(pow(4, 3) == 64);
  CHECK(pow(5, 3) == 125);
  CHECK(pow(10, 8) == 100000000);
}
