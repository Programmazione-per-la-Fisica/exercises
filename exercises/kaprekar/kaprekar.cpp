#include <iostream>
#include <string>
#include <cassert>
#include <iterator>
#include <algorithm>

bool verifyKaprekar(int num) {

  short steps {0};
  int difference {0};
  while(1) {
	++steps;

	std::string ascending { std::to_string(num) };
	std::string descending { ascending };
	std::sort(ascending.begin(), ascending.end());
	std::sort(descending.begin(), descending.end(), std::greater<int>());

	int num1 { std::stoi(ascending) };
	int num2 { std::stoi(descending) };

	difference = std::abs(num2 - num1);
	std::cout << difference << std::endl;
	if(difference == 6174) { break; }
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
