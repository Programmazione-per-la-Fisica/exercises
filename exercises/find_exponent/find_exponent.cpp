#include <cassert>
#include <cmath>
#include <iostream>
#include <string>

int findExponent(int num) {
  std::string sequence = std::to_string(num);
  int length = sequence.size();

  int exponent = 0;
  while (1) {
    int n = std::pow(2, exponent);
    std::string test_string = std::to_string(n);

    // Check digit by digit if the two sequences are identical
    bool match = true;
    for (int i = 0; i != length; ++i) {
      if (test_string[i] != sequence[i]) {
        match = false;
      }
    }
    // If you have a match, the exponent is the right one so you exit the while
    if (match) {
      break;
    }

    // If you haven't found a match you increase the exponent and start over
    ++exponent;
  }

  return exponent;
}

int main() {
  // A bit of testing
  assert(findExponent(8) == 3);
  assert(findExponent(10) == 10);
  assert(findExponent(40) == 12);
  assert(findExponent(25) == 8);
  assert(findExponent(6) == 6);
  assert(findExponent(1) == 0);
}
