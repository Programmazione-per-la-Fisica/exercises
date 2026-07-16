#include <cmath>
#include <iostream>

int main() {
  // inizializzo le variabili che mi servono per il calcolo della media
  int pioggia = 0;
  int N = 0;
  // input utente
  double input_utente;
  while (true) {
    std::cout
        << "Inserisci la quantità di pioggia in mm (99999 per terminare):";

    // controllo che non ci siano caratteri diversi da numeri
    if (!(std::cin >> input_utente)) {
      std::cout << "Valore non valido." << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      continue;
    }
    // controllo che sia un intero
    if (input_utente != std::floor(input_utente)) {
      std::cout << "Valore rimosso: sono accettati solo valori interi."
                << std::endl;
      continue;
    }
    // controllo valori negativi
    if (input_utente < 0) {
      std::cout << "Valore negativo ignorato." << std::endl;
      continue;
    }
    // controllo valore terminazione
    if (input_utente == 99999) {
      break;
    }
    // se tutti i controlli sono passati allora incremento la somma e N
    pioggia += input_utente;
    N += 1;
  }
  // controllo che N sia diverso da 0
  if (N == 0) {
    std::cout << "Impossibile calcolare la media, nessun valore valido inserito"
              << std::endl;
  } else {
    double media = static_cast<double>(pioggia) / N;
    std::cout << "La media giornaliera di pioggia è:" << media << "mm"
              << std::endl;
  }
  return 0;
}