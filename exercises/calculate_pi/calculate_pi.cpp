#include <cmath>
#include <iostream>

double calculatePi(int n) {
  double dx = 1. / n;

  double result = 0.;
  for (int i{}; i < n; ++i) {
    result += dx * 4. / (1 + std::pow(i * dx, 2));
  }
  return result;
}

int main() {
  std::cout << "Write the number of intervals in which the interval [0,1] will "
               "be divided: ";
  int n;
  std::cin >> n;
  std::cout << calculatePi(n) << '\n';
}
