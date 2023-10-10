#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

int towerHanoi(int nDisks) {
  if (nDisks == 1) {
    return 1;
  } else {
    return 1 + 2 * towerHanoi(nDisks - 1);
  }
}

TEST_CASE(
    "Testing the function calculating the number of moves in the hanoi tower") {
  CHECK(towerHanoi(1) == 1);
  CHECK(towerHanoi(2) == 3);
  CHECK(towerHanoi(3) == 7);
  CHECK(towerHanoi(4) == 15);
  CHECK(towerHanoi(5) == 31);
  CHECK(towerHanoi(6) == 63);
  CHECK(towerHanoi(7) == 127);
  CHECK(towerHanoi(8) == 255);
}
