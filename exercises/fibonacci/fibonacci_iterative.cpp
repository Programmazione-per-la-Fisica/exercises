#include <cassert>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

int fibonacci(int n) {
  // n is the position in the Fibonacci sequence
  assert(n >= 1);

  int previous_value{1};
  int current_value{1};
  int result{1};

  for (int i{2}; i < n; ++i) {
    result = current_value + previous_value;
    previous_value = current_value;
    current_value = result;
  }

  return result;
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
