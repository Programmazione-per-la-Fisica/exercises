#include <iostream>

int main() {
  int n{0};
  // Should check if n is positive
  std::cout << "Insert an integer: ";
  std::cin >> n;
  std::cout << "The sum of the first N cubes is "
            << n*n*((n+1)*(n+1))*0.25 << '\n';
}
