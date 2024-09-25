#include <iostream>

double calculate_average(int x1, int x2, int x3, int x4) {
  return (x1 + x2 + x3 + x4) / 4.;
}

int main() {
  std::cout << "Your average grade is: " << calculate_average(28, 26, 29, 30)
            << '\n'
            << "The expected average is: " << 28.25 << '\n';
}
