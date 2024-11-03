# Esercizi di Programmazione per la Fisica

Questa repository contiene una collezione di esercizi in C++ per il corso di Programmazione per la Fisica della laurea triennale in Fisica dell'Università di Bologna.

## Struttura della repository

La repository è strutturata nel seguente modo:

```
├──problemi
│   ├── esercizio_1
│   │   ├── soluzione_1.cpp
│   │   ├── soluzione_2.cpp
│   │   └── README.md
│   ├── esercizio_2
│   |   ├── esercizio_2.cpp
│   |   └── README.md
│   └── ...
└── README.md
```

Ogni esercizio è contenuto in una directory separata e ha un proprio file README.md che contiene la consegna dell'esercizio e alcune indicazioni sulle soluzioni presenti.

## Come compilare gli esercizi

### Usando `g++`

I singoli file `.cpp` delle soluzioni possono essere compilati usando il compilatore `g++`.  
Il comando da usare e':

```shell
g++ -Wall -Wextra nome_file.cpp
```

Volendo si può rinominare l'eseguibile aggiungendo in coda al comando precedente la flag `-o nome_flag`. Di default gli eseguibili vengono chiamati `a.out`.

### Usando `CMAKE`

Nella subdirectory di ogni esercizio e' presente un file `CMakeLists.txt`, che permette la compilazione della soluzione mediante [CMake](https://cmake.org). Per compilare con CMAKE eseguire prima il comando:

```shell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

e poi:

```shell
cmake --build build
```

## Come contribuire

Se vuoi contribuire con nuovi esercizi o nuove soluzioni, segui questi passaggi:

1. Fai una *fork* della repository
1. Aggiungi i tuoi cambiamenti
1. Assicurati di aver formattato il codice
1. Fai il *pull* della repository originale e risolvi eventuali *merge conflict* in locale prima di fare il *push* su remoto
1. Invia una *pull request*, descrivendo dettagliatamente quanto aggiunto nel messaggio

Per mantenere una coerenza nel codice e nello stile, segui le seguenti linee guida:

- Mantieni la struttura stabilita;
- Usa nomi di variabile chiari e descrittivi;
- Usa con coerenza le convenzioni per i nomi di classi, funzioni e variabili (i.e. CamelCase, snake_case);
- Usa il file di configurazione [.clang-format](.clang-format) per formattare il codice;
- Non includere nella repository file di build o configurazioni specifiche del tuo ambiente di lavoro. Aggiorna il [.gitignore](.gitignore) se necessario;
- In caso di modifiche a soluzioni già presenti, scrivi messaggi di *commit* dettagliati.

Se vuoi contribuire, ma non sai da dove iniziare, controlla la scheda [Issues](https://github.com/Programmazione-per-la-Fisica/exercises/issues) sul GitHub della repository.

