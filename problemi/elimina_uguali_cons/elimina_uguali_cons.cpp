#include <iostream>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::vector<int> elimina_uguali_cons(const std::vector<int> V) {
  std::vector<int> V_new;
  // check if V has no elements
  if (V.size() == 0) {
    return V_new;
  }

  // the first element of V must be in V_new
  V_new.push_back(V[0]);

  for (size_t i = 0; i < V.size() - 1; ++i) {
    if (V[i] != V[i + 1]) {
      V_new.push_back(V[i + 1]);
    }
  }
  return V_new;
}

TEST_CASE("testing the elimina_uguali_cons function") {
  CHECK(elimina_uguali_cons({1, 2, 2, -1, 0, 0, 2, 2, 2, 2, 3}) ==
        std::vector<int>{1, 2, -1, 0, 2, 3});
  CHECK(elimina_uguali_cons({2, 4, 4, 4, 5, -3, 0, 0, -2, -2, 4, 4}) ==
        std::vector<int>{2, 4, 5, -3, 0, -2, 4});
  CHECK(elimina_uguali_cons({1, 2, 3}) == std::vector<int>{1, 2, 3});
  CHECK(elimina_uguali_cons({}) == std::vector<int>{});
  CHECK(elimina_uguali_cons({4, 4, 4, 4, 4, 4}) == std::vector<int>{4});
  CHECK(elimina_uguali_cons({1, 2, 3, 5}) == std::vector<int>{1, 2, 3, 5});
  CHECK(elimina_uguali_cons({1, 1, 5, 7, 9}) == std::vector<int>{1, 5, 7, 9});
  CHECK(elimina_uguali_cons({1, 2, 3, 5, 5}) == std::vector<int>{1, 2, 3, 5});
  CHECK(elimina_uguali_cons({1}) == std::vector<int>{1});
}