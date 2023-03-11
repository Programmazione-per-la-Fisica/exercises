#include <cassert>
#include <iostream>

int pow(int base, int exponent) {
  int result{1};
  for (int i{}; i < exponent; ++i) {
    result *= base;
  }
  return result;
}

int main() {
  assert(pow(2, 3) == 8);
  std::cout << "TEST PASSED\n";
  assert(pow(2, 1) == 2);
  std::cout << "TEST PASSED\n";
  assert(pow(2, 0) == 1);
  std::cout << "TEST PASSED\n";
  assert(pow(4, 3) == 64);
  std::cout << "TEST PASSED\n";
  assert(pow(5, 3) == 125);
  std::cout << "TEST PASSED\n";
  assert(pow(10, 8) == 100000000);
  std::cout << "TEST PASSED\n";
}
