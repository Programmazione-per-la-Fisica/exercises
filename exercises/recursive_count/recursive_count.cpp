#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

int recursive_count(std::vector<int>::iterator first,
                    std::vector<int>::iterator last, int value,
                    int counter = 0) {
  if (first == last) {
    return counter;
  } else {
    if (*first == value) {
      ++counter;
    }

    // Shift the iterator towards the end of the vector
    ++first;
    // Repeat the operation with the shortened range
    return recursive_count(first, last, value, counter);
  }
}

int main() {
  std::vector<int> v{1, 2, 4, 6, 7, 4, 3, 5, 6, 7, 8, 4, 2, 3};
  assert(recursive_count(v.begin(), v.end(), 4) == 3);
  std::cout << "TEST PASSED\n";
  assert(recursive_count(v.begin(), v.end(), 3) == 2);
  std::cout << "TEST PASSED\n";
  assert(recursive_count(v.begin(), v.end(), 1) == 1);
  std::cout << "TEST PASSED\n";
  assert(recursive_count(v.begin(), v.end(), 6) == 2);
  std::cout << "TEST PASSED\n";
  std::vector<int> w{4, 2, 4, 5, 6, 7, 4, 4, 3, 2, 4, 5, 7, 5, 4, 3, 5, 7, 4};
  assert(recursive_count(w.begin(), w.end(), 4) == 7);
  std::cout << "TEST PASSED\n";
  assert(recursive_count(w.begin(), w.end(), 2) == 2);
  std::cout << "TEST PASSED\n";
  assert(recursive_count(w.begin(), w.end(), 7) == 3);
  std::cout << "TEST PASSED\n";
  assert(recursive_count(w.begin(), w.end(), 5) == 4);
  std::cout << "TEST PASSED\n";
}
