#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

int fibonacci(int n) {
  if (n < 1) {
    std::cout << "n must be at least one\n";
    return -1;
  } else if (n == 1 || n == 2) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

TEST_CASE(
    "Testing the function calculating the nth element of the fibonacci "
    "sequence") {
  CHECK(fibonacci(2) == 1);
  CHECK(fibonacci(3) == 2);
  CHECK(fibonacci(4) == 3);
  CHECK(fibonacci(5) == 5);
  CHECK(fibonacci(6) == 8);
  CHECK(fibonacci(7) == 13);
  CHECK(fibonacci(8) == 21);
  CHECK(fibonacci(9) == 34);
  CHECK(fibonacci(20) == 6765);
  CHECK(fibonacci(0) == -1);
  CHECK(fibonacci(-5) == -1);
}
