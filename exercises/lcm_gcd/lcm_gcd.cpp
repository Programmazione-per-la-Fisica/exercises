#include <cassert>
#include <iostream>

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

int main() {
  // Test lcm
  std::cout << "Testing lcm function: \n";
  assert(lcm(2, 3) == 6);
  std::cout << "TEST PASSED\n";
  assert(lcm(1, 3) == 3);
  std::cout << "TEST PASSED\n";
  assert(lcm(3, 7) == 21);
  std::cout << "TEST PASSED\n";
  assert(lcm(4, 5) == 20);
  std::cout << "TEST PASSED\n";
  assert(lcm(5, 10) == 10);
  std::cout << "TEST PASSED\n";

  // Test gcm
  std::cout << "Testing gcd function: \n";
  assert(gcd(4, 20) == 4);
  std::cout << "TEST PASSED\n";
  assert(gcd(5, 100) == 5);
  std::cout << "TEST PASSED\n";
  assert(gcd(24, 72) == 24);
  std::cout << "TEST PASSED\n";
  assert(gcd(15, 105) == 15);
  std::cout << "TEST PASSED\n";
  assert(gcd(1, 10) == 1);
  std::cout << "TEST PASSED\n";
}
