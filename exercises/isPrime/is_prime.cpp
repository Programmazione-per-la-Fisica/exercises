#include <cassert>
#include <cmath>
#include <iostream>

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

int main() {
  assert(isPrime(0) == false);
  std::cout << "TEST PASSED\n";
  assert(isPrime(1) == true);
  std::cout << "TEST PASSED\n";
  assert(isPrime(2) == true);
  std::cout << "TEST PASSED\n";
  assert(isPrime(3) == true);
  std::cout << "TEST PASSED\n";
  assert(isPrime(5) == true);
  std::cout << "TEST PASSED\n";
  assert(isPrime(7) == true);
  std::cout << "TEST PASSED\n";
  assert(isPrime(11) == true);
  std::cout << "TEST PASSED\n";
  assert(isPrime(4) == false);
  std::cout << "TEST PASSED\n";
  assert(isPrime(6) == false);
  std::cout << "TEST PASSED\n";
  assert(isPrime(8) == false);
  std::cout << "TEST PASSED\n";
  assert(isPrime(10) == false);
  std::cout << "TEST PASSED\n";
  assert(isPrime(40) == false);
  std::cout << "TEST PASSED\n";
  assert(isPrime(31) == true);
  std::cout << "TEST PASSED\n";
  assert(isPrime(-5) == false);
  std::cout << "TEST PASSED\n";
}
