#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

std::string toBinary(int num) {
  std::string binaryNum = "";

  while (num != 0) {
    num % 2 == 0 ? binaryNum += '0' : binaryNum += '1';
    num /= 2;
  }
  std::reverse(binaryNum.begin(), binaryNum.end());
  return binaryNum;
}

TEST_CASE("Testing the conversion of integers to binary notation") {
  CHECK(toBinary(2) == "10");
  CHECK(toBinary(3) == "11");
  CHECK(toBinary(4) == "100");
  CHECK(toBinary(5) == "101");
  CHECK(toBinary(10) == "1010");
  CHECK(toBinary(40) == "101000");
  CHECK(toBinary(100) == "1100100");
  CHECK(toBinary(101) == "1100101");
}
