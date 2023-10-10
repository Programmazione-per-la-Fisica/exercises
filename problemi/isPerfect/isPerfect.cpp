#include <numeric>
#include <type_traits>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

bool isPerfect(int num) {
  std::vector<int> factors;

  for (int i{1}; i < num; ++i) {
    if (num % i == 0) {
      factors.push_back(i);
    }
  }

  bool isPerf = std::accumulate(factors.begin(), factors.end(), 0) == num;
  return isPerf;
}

TEST_CASE("Testing the isPerfect function") {
  CHECK(isPerfect(6) == true);
  CHECK(isPerfect(28) == true);
  CHECK(isPerfect(496) == true);
  CHECK(isPerfect(12) == false);
  CHECK(isPerfect(97) == false);
  CHECK(isPerfect(55) == false);
}
