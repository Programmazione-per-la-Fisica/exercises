#include <fstream>
#include <iostream>
#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

int find_max_int(std::string const& pathToFile) {
  int max{};

  std::ifstream fileContent{pathToFile};
  std::string value;
  while (getline(fileContent, value)) {
	if (std::stoi(value) > max) { max = std::stoi(value); }
  }

  return max;
}

TEST_CASE("") {
  CHECK(find_max_int("./file.txt") == 15635);
}
