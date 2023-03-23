#include <cassert>
#include <cmath>
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

bool isPrime(int num) {
  if (num <= 1) {
    return false;
  }

  for (int i{2}; i <= std::sqrt(num); ++i) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

TEST_CASE("Testing the isPrime function") {
  CHECK(isPrime(0) == false);
  CHECK(isPrime(1) == false);
  CHECK(isPrime(2) == true);
  CHECK(isPrime(3) == true);
  CHECK(isPrime(5) == true);
  CHECK(isPrime(7) == true);
  CHECK(isPrime(11) == true);
  CHECK(isPrime(4) == false);
  CHECK(isPrime(6) == false);
  CHECK(isPrime(8) == false);
  CHECK(isPrime(10) == false);
  CHECK(isPrime(40) == false);
  CHECK(isPrime(31) == true);
  CHECK(isPrime(-5) == false);
}
