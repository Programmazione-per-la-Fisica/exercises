#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

bool verifyKaprekar(int num) {
  short steps{};
  int difference{};

  while (true) {
    ++steps;

	// Create two strings and initialize them to the number converted to a string
    std::string ascending{std::to_string(num)};
    std::string descending{ascending};
	// Then you sort the two strings, one in ascending and the other in descending order
    std::sort(ascending.begin(), ascending.end());
    std::sort(descending.begin(), descending.end(), std::greater());

	// Convert the two resulting numbers to integers and calculate their difference (in abs value)
    int num1{std::stoi(ascending)};
    int num2{std::stoi(descending)};
    difference = std::abs(num2 - num1);
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
