#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>

bool verifyKaprekar(int num) {
  short steps{};
  int difference{};

  while (true) {
    ++steps;

	// Create two strings and initialize them to the number converted to a string
    std::string ascending{std::to_string(num)};
    std::string descending{ascending};
	// Then you sort the two strings, one in ascending and the other in descending order
    std::sort(ascending.begin(), ascending.end());
    std::sort(descending.begin(), descending.end(), std::greater());

	// Convert the two resulting numbers to integers and calculate their difference (in abs value)
    int num1{std::stoi(ascending)};
    int num2{std::stoi(descending)};
    difference = std::abs(num2 - num1);
    if (difference == 6174) {
      break;
    }
    num = difference;
  }

  return steps <= 7;
}

int main() {
  assert(verifyKaprekar(4925));
  assert(verifyKaprekar(1029));
  assert(verifyKaprekar(4956));
  assert(verifyKaprekar(8573));
  assert(verifyKaprekar(3921));
  assert(verifyKaprekar(9483));
  assert(verifyKaprekar(8937));
  assert(verifyKaprekar(7893));
}
