#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

std::string rmSpecialCharacters(std::string&& result) {
  const std::vector<char> specialCharacters = {'.', '!', '@', '#', '$', '%',
                                               '^', '&', '*', '(', ')'};

  result.erase(std::remove_if(result.begin(), result.end(),
                              [&specialCharacters](char c) {
                                return (std::find(specialCharacters.begin(),
                                                  specialCharacters.end(), c) !=
                                        specialCharacters.end());
                              }),
               result.end());
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
