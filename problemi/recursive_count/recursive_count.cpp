#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

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

TEST_CASE("Testing recursive_count") {
  std::vector<int> v{1, 2, 4, 6, 7, 4, 3, 5, 6, 7, 8, 4, 2, 3};
  CHECK(recursive_count(v.begin(), v.end(), 4) == 3);
  CHECK(recursive_count(v.begin(), v.end(), 3) == 2);
  CHECK(recursive_count(v.begin(), v.end(), 1) == 1);
  CHECK(recursive_count(v.begin(), v.end(), 6) == 2);
  std::vector<int> w{4, 2, 4, 5, 6, 7, 4, 4, 3, 2, 4, 5, 7, 5, 4, 3, 5, 7, 4};
  CHECK(recursive_count(w.begin(), w.end(), 4) == 7);
  CHECK(recursive_count(w.begin(), w.end(), 2) == 2);
  CHECK(recursive_count(w.begin(), w.end(), 7) == 3);
  CHECK(recursive_count(w.begin(), w.end(), 5) == 4);
}
