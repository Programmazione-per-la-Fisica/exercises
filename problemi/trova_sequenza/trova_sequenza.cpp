#include <algorithm>
#include <array>
#include <iostream>
#include <random>

int main() {
  // random bit generator: seed, engine, distribution
  std::random_device rd;
  std::default_random_engine eng(rd());
  auto dist = std::uniform_int_distribution<>(1, 100);

  // define S,Nmax,counter
  const std::array<int, 6> S = {14, 23, 51, 55, 68, 76};
  std::array<int, 6> S_casuale;
  int Nmax = 1000000;
  int counter = 0;

  // generate the random sequences
  while (counter < Nmax) {
    for (size_t i = 0; i < 6; ++i) {
      S_casuale[i] = dist(eng);
    }
    counter += 1;

    // if found
    if (S_casuale == S) {
      std::cout << "S found in " << counter << " attempts!" << std::endl;
      break;
    }
  }
  // if not found
  if (counter == Nmax) {
    std::cout << "S not found" << std::endl;
  }
  
  return 0;
}