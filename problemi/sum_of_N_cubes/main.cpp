#include <cassert>
#include <iostream>

int pow(int base, int exp) {
  assert(exp >= 0);
  int result{1};
  for (int i{0}; i != exp; ++i) {
    result *= base;
  }
  return result;
}

int main() {
  std::cout << "Insert an integer >= 1: ";
  int n;
  std::cin >> n;
  if (!(std::cin && n >= 1)) {
    std::cerr << "Invalid argument\n";
    return EXIT_FAILURE;
  }

  int result{1};
  for (int i{2}; i <= n; ++i) {
    result += pow(i, 3);
  }
  std::cout << "The sum of the first " << n << " cubes is " << result << '\n';
}
