#include <iostream>

int main() {
  std::cout << "Insert an integer >= 1: ";
  int n;
  std::cin >> n;
  if (!(std::cin && n >= 1)) {
    std::cerr << "Invalid argument\n";
    return EXIT_FAILURE;
  }

  std::cout << "The sum of the first " << n << " cubes is "
            << n * n * (n + 1) * (n + 1) / 4 << '\n';
}
