#include <cmath>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

bool is_prime(int num) {
  if (num == 2) {
    return true;
  }
  if (num < 2 || num % 2 == 0) {
    return false;
  }

  for (int i{3}; i*i <= num; i+=2) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

TEST_CASE("Testing the is_prime function: special cases") {
  CHECK(is_prime(-5) == false);
  CHECK(is_prime(0) == false);
  CHECK(is_prime(1) == false);
}

TEST_CASE("Testing the is_prime function: some prime numbers") {
  CHECK(is_prime(2) == true);
  CHECK(is_prime(3) == true);
  CHECK(is_prime(5) == true);
  CHECK(is_prime(7) == true);
  CHECK(is_prime(11) == true);
  CHECK(is_prime(359) == true);
}

TEST_CASE("Testing the is_prime function: some non-prime numbers") {
  CHECK(is_prime(4) == false);
  CHECK(is_prime(8) == false);
  CHECK(is_prime(10) == false);
  CHECK(is_prime(27) == false);
  CHECK(is_prime(45) == false);
  CHECK(is_prime(150) == false);
  CHECK(is_prime(209) == false);
}
