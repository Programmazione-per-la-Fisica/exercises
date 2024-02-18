#include <numeric>
#include <vector>
#include <cassert>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

bool isPerfect(int num) {
  assert(num > 0);

  std::vector<int> factors{1};

  for (int i{2}; i < num; ++i) {
    if (num % i == 0) {
      factors.push_back(i);
    }
  }

  return std::accumulate(factors.begin(), factors.end(), 0) == num;
}

TEST_CASE("Testing the isPerfect function") {
  CHECK(isPerfect(6) == true);
  CHECK(isPerfect(28) == true);
  CHECK(isPerfect(496) == true);
  CHECK(isPerfect(12) == false);
  CHECK(isPerfect(97) == false);
  CHECK(isPerfect(55) == false);
}
