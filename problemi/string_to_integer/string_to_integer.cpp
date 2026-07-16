#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool prova_conversione(const std::string& s, int& carattere) {
  try {
    size_t pos;
    carattere = std::stoi(s, &pos);
    return pos == s.length();
  } catch (...) {
    return false;
  }
}

int main() {
  std::vector<std::string> V;
  std::string carattere;

  std::cout << "Inserisci valori separati da spazi ('fine' per concludere)"
            << std::endl;

  while (std::cin >> carattere && carattere != "fine") {
    V.push_back(carattere);
  }

  if (V.size() == 0) {
    std::cout << "V is empty" << std::endl;
    return 0;
  }
  if (V.size() == 1) {
    std::cout << "V={" << V[0] << "}" << std::endl;
    return 0;
  }
  auto it = V.begin();
  while (it != V.end()) {
    int temp;
    if (!prova_conversione(*it, temp)) {
      it = V.erase(it);
    } else {
      ++it;
    }
  }
  std::cout << "\nVettore con solo interi: V={";
  for (size_t i = 0; i < V.size(); i++) {
    std::cout << V[i] << ", ";
  }
  std::cout << "}" << std::endl;
  return 0;
}
