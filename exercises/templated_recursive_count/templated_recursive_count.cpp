#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
int recursive_count(std::vector<T> const& vec,
                    typename std::vector<T>::iterator first,
                    typename std::vector<T>::iterator last, T value) {
  int counter = 0;
  while (first != last) {
    if (*first == value) {
      ++counter;
    }

    // Shift the iterator towards the end of the vector
    ++first;
    // Repeat the operation with the shortened range
    recursive_count(vec, first, last, value);
  }

  return counter;
}

int main() {
  // Test chars
  std::cout << "Tests for chars: \n";
  std::vector<char> v{'a', 'b', 'e', 'b', 'u', 'e', 'm', 'a',
                      'w', 'b', 'n', 'a', 'u', 'c', 'a'};
  assert(recursive_count<char>(v, v.begin(), v.end(), 'a') == 4);
  std::cout << "TEST PASSED\n";
  assert(recursive_count<char>(v, v.begin(), v.end(), 'b') == 3);
  std::cout << "TEST PASSED\n";
  assert(recursive_count<char>(v, v.begin(), v.end(), 'e') == 2);
  std::cout << "TEST PASSED\n";
  assert(recursive_count<char>(v, v.begin(), v.end(), 'u') == 2);
  std::cout << "TEST PASSED\n\n";

  // Test bools
  std::cout << "Tests for bools: \n";
  std::vector<bool> w{true,  false, false, true, false, true,
                      false, false, false, true, true,  false};
  assert(recursive_count<bool>(w, w.begin(), w.end(), true) == 5);
  std::cout << "TEST PASSED\n";
  assert(recursive_count<bool>(w, w.begin(), w.end(), false) == 7);
  std::cout << "TEST PASSED\n\n";

  // Test strings
  std::cout << "Tests for strings: \n";
  std::vector<std::string> u{"Giaco",    "Lanzi", "Lanzi", "Tisbeni",
                             "Balducci", "Giaco", "Lanzi"};
  assert(recursive_count<std::string>(u, u.begin(), u.end(), "Giaco") == 2);
  std::cout << "TEST PASSED\n";
  assert(recursive_count<std::string>(u, u.begin(), u.end(), "Lanzi") == 3);
  std::cout << "TEST PASSED\n";
  assert(recursive_count<std::string>(u, u.begin(), u.end(), "Tisbeni") == 1);
  std::cout << "TEST PASSED\n";
  assert(recursive_count<std::string>(u, u.begin(), u.end(), "Balducci") == 1);
  std::cout << "TEST PASSED\n\n";
}
