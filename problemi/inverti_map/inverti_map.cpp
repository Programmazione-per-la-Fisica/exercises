#include <map>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

template <typename K, typename V>  // type of keys and values
std::map<V, std::vector<K>> inverti_map(std::map<K, V>& originale) {
  std::map<V, std::vector<K>> inverso;

  for (auto it = originale.begin(); it != originale.end(); ++it) {
    K chiave_orig = it->first;
    V valore_orig = it->second;

    // look for the original value in the inverse map as key
    auto it_inv = inverso.find(valore_orig);
    if (it_inv == inverso.end()) {
      // if doesn't found just insert the inverse couple in the in the inverse
      // map
      inverso.insert({valore_orig, std::vector<K>{chiave_orig}});
    } else {
      // if found just add the original key in the inverse map as value
      it_inv->second.push_back(chiave_orig);
    }
  }
  return inverso;
}

TEST_CASE("testing the inverti_diz function") {
  std::map<std::string, int> m1 = {
      {"g", 1}, {"o", 1}, {"p", 3}, {"l", 2}, {"a", 3}};
  std::map<int, std::vector<std::string>> expected1 = {
      {1, {"g", "o"}}, {2, {"l"}}, {3, {"a", "p"}}};
  CHECK(inverti_map(m1) == expected1);

  std::map<int, int> m2 = {};
  CHECK(inverti_map(m2).empty() == true);

  std::map<std::string, std::vector<int>> m3 = {
      {"g", {1, 2}}, {"o", {2, 1}}, {"t", {1, 2}}};
  std::map<std::vector<int>, std::vector<std::string>> expected3 = {
      {{1, 2}, {"g", "t"}}, {{2, 1}, {"o"}}};
  CHECK(inverti_map(m3) == expected3);
}
