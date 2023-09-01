#include <algorithm>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

int findMaxProd_1(std::vector<int> const& vec) {
  int max{};

  while (true) {
    auto it = std::adjacent_find(vec.begin(), vec.end(),
                                 [max](auto a, auto b) { return a * b > max; });

    if (it != vec.end()) {
      max = *it * *(it + 1);
    } else {
      break;
    }
  }

  return max;
}

int findMaxProd_2(std::vector<int> const& vec) {
  int max{};
  int temp{};

  while (
      std::adjacent_find(vec.begin(), vec.end(), [max, &temp](auto a, auto b) {
        temp = a * b;
        return a * b > max;
      }) != vec.end()) {
    max = temp;
  }

  return max;
}

TEST_CASE("Testing findMaxProd_1 function") {
  CHECK(findMaxProd_1({1, 2, 3, 4, 5}) == 20);
  CHECK(findMaxProd_1({1, 4, 5, 8, 7, 2}) == 56);
  CHECK(findMaxProd_1({20, 3, 1, 2, 4}) == 60);
}

TEST_CASE("Testing findMaxProd_2 function") {
  CHECK(findMaxProd_2({1, 2, 3, 4, 5}) == 20);
  CHECK(findMaxProd_2({1, 4, 5, 8, 7, 2}) == 56);
  CHECK(findMaxProd_2({20, 3, 1, 2, 4}) == 60);
}
