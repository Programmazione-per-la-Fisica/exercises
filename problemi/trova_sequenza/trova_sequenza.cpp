#include <algorithm>
#include <array>
#include <iostream>
#include <random>

int main() {
  // random bit generator
  std::random_device rd;
  std::default_random_engine eng(rd());
  auto dist = std::uniform_int_distribution<>(1, 100);
  // definisco S, la sequenza casuale, il counter e Nmax
  const std::array<int, 6> S = {14, 23, 51, 55, 68, 76};
  std::array<int, 6> S_casuale;
  int Nmax = 1000000;
  int counter = 0;

  while (counter < Nmax) {
    for (size_t i = 0; i < 6; ++i) {
      S_casuale[i] = dist(eng);
    }
    counter += 1;
    if (S_casuale == S) {
      std::cout << "Ho trovato S in " << counter << " tentativi!" << std::endl;
      break;
    }
  }
  if (counter == Nmax) {
    std::cout << "Non ho trovato S" << std::endl;
  }
  return 0;
}