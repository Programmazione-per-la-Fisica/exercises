#include <cassert>
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

int gcd(int a, int b) {
  int t{};

  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }

  return a;
}

int lcm(int a, int b) {
  int lcm{};

  for (int i{1}; i <= a * b / gcd(a, b); ++i) {
    if (i % a == 0 && i % b == 0) {
      lcm = i;
      break;
    }
  }

  return lcm;
}


TEST_CASE("Testing the functions calculating the gcd and lcm") {
  // Test lcm
  std::cout << "Testing lcm function: \n";
  CHECK(lcm(2, 3) == 6);
  CHECK(lcm(1, 3) == 3);
  CHECK(lcm(3, 7) == 21);
  CHECK(lcm(4, 5) == 20);
  CHECK(lcm(5, 10) == 10);

  // Test gcm
  std::cout << "Testing gcd function: \n";
  CHECK(gcd(4, 20) == 4);
  CHECK(gcd(5, 100) == 5);
  CHECK(gcd(24, 72) == 24);
  CHECK(gcd(15, 105) == 15);
  CHECK(gcd(1, 10) == 1);
}
