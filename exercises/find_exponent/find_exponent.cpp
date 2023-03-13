#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

int findExponent(int num) {
  std::string sequence{std::to_string(num)};
  int length = sequence.size();

  int exponent{};
  while (true) {
    int n = std::pow(2, exponent);
    std::string test_string{std::to_string(n)};

    // Check digit by digit if the two sequences are identical
    if (test_string.substr(0, length) == sequence) {
      break;
    } else {
      // If you haven't found a match you increase the exponent and start over
      ++exponent;
    }
  }

  return exponent;
}

TEST_CASE("Testing the findExponent function") {
  CHECK(findExponent(8) == 3);
  CHECK(findExponent(10) == 10);
  CHECK(findExponent(40) == 12);
  CHECK(findExponent(25) == 8);
  CHECK(findExponent(6) == 6);
  CHECK(findExponent(1) == 0);
}
