#include <iostream>
#include <vector>

int main() {
  int i;
  std::vector<int> v;

  while (std::cin >> i) {
    v.push_back(i);
  }

  bool is_palindrome{true};
  long int n{std::ssize(v)};

  if (n > 0) {
    for (long int j{0}; j != n / 2; ++j) {
      is_palindrome = v[j] != v[n - 1 - j] ? false : is_palindrome;
    }
    std::cout << std::boolalpha << is_palindrome << '\n';
  } else {
    std::cout << "Vector size is 0, can't be palindrome!\n";
  }
}