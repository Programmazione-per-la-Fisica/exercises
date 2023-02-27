#include <iostream>

int main()
{
  int smallest{0};
  std::cout << "Insert a sequence of numbers (stop with Ctrl-D) \n";
  while (std::cin.good()) {
    int n{0};
    std::cin >> n;
    if (n < smallest) smallest = n;
  }
  std::cout << "The smallest number entered is " << smallest << '\n';
}
