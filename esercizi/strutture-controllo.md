# Strutture di Controllo

### 1. Scrivere un programma che, dati 3 numeri `a`, `b` e `c` in input, stampi se `c` è più piccolo di `a`, più grande di `b` o compreso tra i due.

In un `if-else` statement, il blocco `else` è controllato solo se la prima condizione è falsa.

Cosa succede se l'`else` statement è formato esso stesso da un `if-else` statement?

### 2. Scrivere un programma che, dati in input due numeri `a` e `b`, trovi la soluzione dell'equazione `ax + b = 0`.

Il programma deve saper gestire soluzioni impossibili o indeterminate.

### 3. Qual è l'output dei seguenti programmi?

```c++
int i{5};
while (i > 0)
{
  std::cout << i << ' ';
  --i;
}
```

---

```c++
int i{5};
while (--i > 0)
{
  std::cout << i << ' ';
}
```

---

```c++
int i{5};
while (i-- > 0)
{
  std::cout << i << ' ';
}
```

### 4. Qual è l'output dei seguenti programmi?

```c++
for (int i{0}; i != 5; ++i) {
  std::cout << i << ' ';
}
```

---

```c++
for (int i{5}; i > 0; --i) {
  std::cout << i << ' ';
}
```

---

```c++
for (int i{0}; i < 5; i += 2){
  std::cout << i << ' ';
}
```

### 5. Svolgi gli esercizi nelle slide

* the smallest of three numbers
* the largest/smallest of N numbers
* accumulate 0.001
