#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

int letterDistance(char first, char second) {
  std::vector<char> alphabet{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                             'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                             's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  auto first_iterator{std::find(alphabet.begin(), alphabet.end(), first)};
  auto second_iterator{std::find(alphabet.begin(), alphabet.end(), second)};

  return std::abs(std::distance(first_iterator, second_iterator));
}

TEST_CASE("Testing the distance between letters in the alphabet") {
  CHECK(letterDistance('a', 'c') == 2);
  CHECK(letterDistance('d', 'i') == 5);
  CHECK(letterDistance('a', 'z') == 25);
  CHECK(letterDistance('b', 't') == 18);
  CHECK(letterDistance('z', 'a') == 25);
  CHECK(letterDistance('s', 'y') == letterDistance('y', 's'));
  CHECK(letterDistance('r', 'r') == 0);
}
