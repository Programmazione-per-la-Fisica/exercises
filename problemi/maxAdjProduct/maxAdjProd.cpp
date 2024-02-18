#include <algorithm>
#include <vector>
#include <cassert>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

int findMaxProd(std::vector<int> const& vec) {
  assert(!vec.empty());

  int max{0};
  for (auto it = vec.begin(), e = vec.end() - 1; it != e; ++it) {
    int prod{*it * *(it + 1)};
    if (prod > max) {
      max = prod;
    }
  }

  return max;
}

TEST_CASE("Testing findMaxProd function") {
  CHECK(findMaxProd({1, 2, 3, 4, 5}) == 20);
  CHECK(findMaxProd({1, 4, 5, 8, 7, 2}) == 56);
  CHECK(findMaxProd({20, 3, 1, 2, 4}) == 60);
  CHECK(findMaxProd({2, 3, 3, 4}) == 12);
  CHECK(findMaxProd({4, 5, 2, 8, 8, 2}) == 64);
  CHECK(findMaxProd({4, 4, 4, 4, 4, 4}) == 16);
  CHECK(findMaxProd({3, 4, 6, -8, 5}) == 24);
  CHECK(findMaxProd({4, 5, 2, 8, 0, 3}) == 20);
}
