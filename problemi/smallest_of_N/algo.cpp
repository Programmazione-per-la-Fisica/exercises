#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::cout << "Insert a sequence of numbers (stop with Ctrl-D) \n";
  std::vector<int> ivec{std::istream_iterator<int>{std::cin},
                        std::istream_iterator<int>{}};
  std::cout << "The smallest number entered is "
            << *std::min_element(ivec.begin(), ivec.end()) << '\n';
}
