#include <algorithm>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

int findMaxProd(std::vector<int> const& vec) {
  int max{};
  for(auto it{vec.begin()}; it != vec.end()-1; ++it) {
	int prod{ *it * *(it+1) };
	if (prod > max) { max = prod; }
  }

  return max;
}

TEST_CASE("Testing findMaxProd function") {
  CHECK(findMaxProd({1,2,3,4,5}) == 20);
  CHECK(findMaxProd({1,4,5,8,7,2}) == 56);
  CHECK(findMaxProd({20,3,1,2,4}) == 60);
}
