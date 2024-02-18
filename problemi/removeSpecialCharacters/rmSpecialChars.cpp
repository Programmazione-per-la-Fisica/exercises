#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::string rmSpecialCharacters(std::string const& str) {
  std::vector<char> const specialCharacters = {'.', '!', '@', '#', '$', '%',
                                               '^', '&', '*', '(', ')'};

  std::string result;
  std::for_each(str.begin(), str.end(), [&](char c) {
    // If the caracter is not in the list of special characters, you can
    // append it to the string
    if (std::find(specialCharacters.begin(), specialCharacters.end(), c) ==
        specialCharacters.end()) {
      result += c;
    }
  });
  return result;
}

TEST_CASE("Testing the function for removing special characters in a string") {
  CHECK(rmSpecialCharacters("Coniglio*") == "Coniglio");
  CHECK(rmSpecialCharacters("Ric*cione") == "Riccione");
  CHECK(rmSpecialCharacters("Man(iglia*") == "Maniglia");
  CHECK(rmSpecialCharacters("Budrio") == "Budrio");
  CHECK(rmSpecialCharacters("#Radicchio") == "Radicchio");
  CHECK(rmSpecialCharacters("!Att$enzi%one^") == "Attenzione");
}
