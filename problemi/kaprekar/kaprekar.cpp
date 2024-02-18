#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

bool verifyKaprekar(int num) {

  int steps{0};

  while (true) {
    ++steps;

    // create two strings as the number converted to a string
    auto ascending = std::to_string(num);
    auto descending = ascending;
    // sort the two strings, one in ascending and the other in descending order
    std::sort(ascending.begin(), ascending.end());
    std::sort(descending.begin(), descending.end(), std::greater<>{});

    // Convert the two resulting numbers to integers and calculate their
    // difference (in abs value)
    auto const num1 = std::stoi(ascending);
    auto const num2 = std::stoi(descending);
    auto const difference = std::abs(num2 - num1);
    if (difference == 6174) {
      break;
    }
    num = difference;
  }

  return steps <= 7;
}

TEST_CASE("Testing the algorithm verifying the kaprekar property") {
  CHECK(verifyKaprekar(4925));
  CHECK(verifyKaprekar(1029));
  CHECK(verifyKaprekar(4956));
  CHECK(verifyKaprekar(8573));
  CHECK(verifyKaprekar(3921));
  CHECK(verifyKaprekar(9483));
  CHECK(verifyKaprekar(8937));
  CHECK(verifyKaprekar(7893));
}
