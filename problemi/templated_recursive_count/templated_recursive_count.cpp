#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

template <typename Iterator, typename E>
int recursive_count(Iterator first, Iterator last, E value, int counter = 0) {
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

TEST_CASE("Testing the templated recursive count with char") {
  // Test chars
  std::vector<char> v{'a', 'b', 'e', 'b', 'u', 'e', 'm', 'a',
                      'w', 'b', 'n', 'a', 'u', 'c', 'a'};
  CHECK(recursive_count(v.begin(), v.end(), 'a') == 4);
  CHECK(recursive_count(v.begin(), v.end(), 'b') == 3);
  CHECK(recursive_count(v.begin(), v.end(), 'e') == 2);
  CHECK(recursive_count(v.begin(), v.end(), 'u') == 2);
}

TEST_CASE("Testing the templated recursive count with bool") {

  std::vector<bool> w{true,  false, false, true, false, true,
                      false, false, false, true, true,  false};
  CHECK(recursive_count(w.begin(), w.end(), true) == 5);
  CHECK(recursive_count(w.begin(), w.end(), false) == 7);
}

TEST_CASE("Testing the templated recursive count with string") {
  std::vector<std::string> u{"Giaco",    "Lanzi", "Lanzi", "Tisbeni",
                             "Balducci", "Giaco", "Lanzi"};
  CHECK(recursive_count(u.begin(), u.end(), "Giaco") == 2);
  CHECK(recursive_count(u.begin(), u.end(), "Lanzi") == 3);
  CHECK(recursive_count(u.begin(), u.end(), "Tisbeni") == 1);
  CHECK(recursive_count(u.begin(), u.end(), "Balducci") == 1);
}
