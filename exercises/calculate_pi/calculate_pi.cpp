#include <cmath>
#include <iostream>

float calculatePi(int n) {
  float dx = 1. / n;

  float result = 0.;
  for (int i{}; i < n; ++i) {
    result += dx * 4. / (1 + std::pow(i * dx, 2));
  }
  return result;
}

int main() {
  std::cout << "Write the number of intervals in which the interval [0,1] will "
               "be divided: \n";
  int n;
  std::cin >> n;
  std::cout << calculatePi(n) << std::endl;
}
