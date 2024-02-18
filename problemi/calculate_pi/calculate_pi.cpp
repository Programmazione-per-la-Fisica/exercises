#include <cassert>
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

double calculatePi(int n) {
  assert(n > 0);

  auto const dx = 1. / n;
  double result = 0.;
  for (int i{0}; i != n; ++i) {
    auto const x = (i + .5) * dx;
    result += 1. / (1 + x * x);
  }
  return dx * 4. * result;
}

TEST_CASE("Test that the function estimates the value of pi correctly") {
  CHECK(doctest::Approx(calculatePi(100)).epsilon(0.0001) == M_PI);
}
