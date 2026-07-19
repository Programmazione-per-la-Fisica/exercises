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

  std::cout << "Insert a sequence of space-separated values ('end' to finish)"
            << std::endl;

  // create V
  while (std::cin >> carattere && carattere != "end") {
    V.push_back(carattere);
  }

  // clean V
  auto it = V.begin();
  while (it != V.end()) {
    int temp;
    if (!prova_conversione(*it, temp)) {
      it = V.erase(it);
    } else {
      ++it;
    }
  }

  // if V is now empty
  if (V.size() == 0) {
    std::cout << "V is empty" << std::endl;
    return 0;
  }

  // print V
  std::cout << "\nVettore con solo interi: V={";
  for (size_t i = 0; i < V.size(); i++) {
    std::cout << V[i];
    if (i != V.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "}" << std::endl;
  return 0;
}
