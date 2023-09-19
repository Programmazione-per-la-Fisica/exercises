#include <cmath>
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

double calculatePi(int n) {
  double dx = 1. / n;

  double result = 0.;
  for (int i{}; i < n; ++i) {
    result += dx * 4. / (1 + std::pow(i * dx, 2));
  }
  return result;
}

TEST_CASE("Test that the function estimates the value of pi correctly") {
  CHECK(doctest::Approx(calculatePi(100)).epsilon(0.0001) == M_PI);
}
