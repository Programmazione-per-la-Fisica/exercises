#include <iostream>

int pow(int base, int exp) {
  // Should check if exp is positive and avoid overflows
  int result{1};
  for (int i = 0; i < exp; ++i) {
    result *= base;
  }
  return result;
}

int main() {
  int n{0};
  int result{0};
  // Should check if n is positive
  std::cout << "Insert an integer: ";
  std::cin >> n;
  for (int i = i; i < n+1; ++i) {
    result += pow(i, 3);
  }
  std::cout << "The sum of the first N cubes is " << result << '\n';
}
