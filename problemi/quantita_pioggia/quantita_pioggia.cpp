#include <cmath>
#include <iostream>

int main() {
  double pioggia = 0.0;
  int N = 0;
  double input_utente;
  while (true) {
    std::cout << "Enter the rainfall amount in mm (99999 to finish)";

    // check for invalid characters
    if (!(std::cin >> input_utente)) {
      std::cout << "Invalid Value." << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      continue;
    }
    // check if input is an integer
    if (input_utente != std::floor(input_utente)) {
      std::cout << "Value removed: only integers value are accepted."
                << std::endl;
      continue;
    }
    // check if input is positive
    if (input_utente < 0) {
      std::cout << "Negative value ignored." << std::endl;
      continue;
    }
    // check for termination value
    if (input_utente == 99999) {
      break;
    }
    // increase
    pioggia += input_utente;
    N += 1;
  }
  // check if N!=0 and calculation of the average
  if (N == 0) {
    std::cout << "Unable to calcolate the average, no valid value entered."
              << std::endl;
  } else {
    double media = pioggia / N;
    std::cout << "The daily average rainfall is:" << media << "mm" << std::endl;
  }
  return 0;
}