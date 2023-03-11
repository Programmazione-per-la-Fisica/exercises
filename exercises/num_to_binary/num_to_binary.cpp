#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

std::string toBinary(int num) {
  std::string binaryNum = "";

  while (num != 0) {
    binaryNum += std::to_string(num % 2);
    num /= 2;
  }
  std::reverse(binaryNum.begin(), binaryNum.end());
  return binaryNum;
}

int main() {
  // Now we test the function for some numbers
  assert(toBinary(2) == "10");
  std::cout << "TEST PASSED\n";
  assert(toBinary(3) == "11");
  std::cout << "TEST PASSED\n";
  assert(toBinary(4) == "100");
  std::cout << "TEST PASSED\n";
  assert(toBinary(5) == "101");
  std::cout << "TEST PASSED\n";
  assert(toBinary(10) == "1010");
  std::cout << "TEST PASSED\n";
  assert(toBinary(40) == "101000");
  std::cout << "TEST PASSED\n";
  assert(toBinary(100) == "1100100");
  std::cout << "TEST PASSED\n";
  assert(toBinary(101) == "1100101");
  std::cout << "TEST PASSED\n";
}
