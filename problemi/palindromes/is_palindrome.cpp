#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  for (int i; std::cin >> i;) {
    v.push_back(i);
  }

  bool is_palindrome{true};
  long int const n{std::ssize(v)};

  for (long int i{0}; i != n / 2; ++i) {
    is_palindrome = is_palindrome && v[i] == v[n - 1 - i];
  }
  std::cout << std::boolalpha << is_palindrome << '\n';
}