#include <cassert>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

int fibonacci(int n) {
  // n is the position in the Fibonacci sequence
  assert(n >= 1);

  return (n == 1 || n == 2) ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

TEST_CASE(
    "Testing the function calculating the nth element of the fibonacci "
    "sequence") {
  CHECK(fibonacci(1) == 1);
  CHECK(fibonacci(2) == 1);
  CHECK(fibonacci(3) == 2);
  CHECK(fibonacci(4) == 3);
  CHECK(fibonacci(9) == 34);
  CHECK(fibonacci(20) == 6765);
}
