<!-- markdownlint-disable-file MD014, MD028 -->
# Esercizio: calcolo vettoriale

## Descrizione

Scrivere, utilizzando i diversi strumenti forniti dal C++, alcuni programmi che
permettano di eseguire operazioni di calcolo vettoriale.
In seguito, sono proposti più approcci risolutivi che fanno uso di alcuni tra i
diversi concetti presentati nel corso.

## Versione _base_

Preparare un programma che, letti da tastiera due vettori in uno spazio reale
bidimensionale, stampi a schermo il risultato di una tra le operazioni di
_somma_ vettoriale_ (`+`), _prodotto scalare tra vettori_ (`*`) o
_prodotto vettoriale_ (`x`).

Si consiglia di:

- rappresentare i vettori tramite `double`, che corrispondono alle loro
  componenti _x_ e _y_;
- rappresentare le tre operazioni `+`, `*`, `x` tramite una `std::string`.

> [!NOTE]
> Ai fini dell'esercizio, cominciare assumendo che l'input sia fornito
> dall'utente in modo corretto.

> [!TIP]
> Per iniziare, potete avvalervi dell'istruzione `if` discussa nel capitolo
> `flow_control` del corso.

In seguito:

1. utilizzare una singola variabile `char` per rappresentare l'operazione;
2. utilizzare l'istruzione `switch` invece dell'`if`;
3. passare al calcolo delle operazioni in uno spazio tridimensionale
4. gestire eventuali errori di input.

## Versione _intermedia_

Utilizzando `struct` o `class`, implementare un tipo _user defined_ che
rappresenti vettori in uno spazio reale bidimensionale.
Inoltre, utilizzando l'overload di operatori, implementare le operazioni di
_somma vettoriale_ (`+=`, `+`), _differenza vettoriale_ (`-`), e _prodotto di
uno scalare per un vettore_ (`*=`, `*`).
Infine, aggiungere due funzioni libere `dot` e `cross` che implementino
rispettivamente il prodotto scalare e quello vettoriale tra vettori.
Cominciare lo sviluppo partendo dalla preparazione di un adeguato insieme di
test che verifichi la correttezza delle operazioni utilizzando `doctest.h`.

> [!TIP]
> Si consiglia di ridurre il numero di parti del codice in cui i calcoli sono
> effettuati per componenti, riferendo dove possibile il calcolo per una
> specifica operazione ad operazioni vettoriali già implementate.

In seguito, estendere il tipo _user defined_ per rappresentare vettori in uno
spazio tridimensionale. Quanta parte del calcolo delle operazioni vettoriali
avete dovuto adattare per funzionare in tre dimensioni?

> [!TIP]
> Confrontate il vostro codice con quello di altri studenti che hanno svolto
> l'esercizio e discutete pro e contro di ciascuna implementazione coi vostri
> compagni di corso o coi docenti.
