#include <iostream>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::vector<int> elimina_uguali_cons(std::vector<int> L) {
  if (L.size() == 0 || L.size() == 1) {
    return L;
  }
  std::vector<int> L_new;
  L_new.push_back(L[0]);
  for (size_t i = 0; i < L.size() - 1; ++i) {
    if (L[i] != L[i + 1]) {
      L_new.push_back(L[i + 1]);
    }
  }
  return L_new;
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