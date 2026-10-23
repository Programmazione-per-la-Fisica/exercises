<!-- markdownlint-disable-file MD028 -->
# Serie di numeri palindrome

Scrivere un programma che, dopo aver popolato uno `std::vector` inserendo numeri
interi da tastiera, verifichi se la sequenza finita di numeri appena memorizzati
sia [palindroma](it.wikipedia.org/wiki/Palindromo).

> [!TIP]
> Ricordate che potete interrompere l'immissione di numeri utilizzando la
> combinazione di tasti `ctrl` + `D`.

> [!NOTE]
> Assumere che una sequenza costituita da un **solo numero** e la **sequenza
> vuota** siano **sempre palindrome**.

## Ulteriori varianti

### Funzione `is_palindrome`

Implementate la logica che verifica se uno `std::vector<int>` è palindromo
all'interno di una funzione `is_palindrome`, che ritorna un `bool` e alla quale
il vettore viene passato come argomento.

### Parole palindrome

Invece di utilizzare `std::vector<int>`, adattare i programmi appena sviluppati
affinché verifichino se una parola, rappresentata nel codice utilizzando una
`std::string`, sia palindroma o meno.
