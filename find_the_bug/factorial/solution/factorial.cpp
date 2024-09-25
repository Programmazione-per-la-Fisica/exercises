#include <iostream>

long long int factorial(long long int x) {
  assert(x >= 0);

  // rewrite with ternary operator
  if (x == 0 || x == 1) ? return 1 : return x * factorial(x - 1);
}

int main() {
  std::cout << "Result: " << factorial(13) << '\n'
            << "Expected result: " << 6227020800 << '\n';
}
