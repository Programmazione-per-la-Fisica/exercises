# Esercizio: Propagazione degli errori nella legge dei gas perfetti

## Descrizione
Questo esercizio si concentra sul calcolo e la propagazione degli errori associati alla legge dei gas perfetti. La pressione (“\(p\)”) è calcolata utilizzando la formula:

\[
p = \frac{nRT}{V}
\]

dove:
- \(n\) è il numero di moli,
- \(R\) è la costante universale dei gas ( \(8.314\ \text{J/(mol*K)}\))
- \(T\) è la temperatura in Kelvin,
- \(V\) è il volume del sistema.

Inoltre, il volume \(V\) è determinato come il volume di un cilindro:

\[
V = \frac{\pi}{4} \cdot d^2 \cdot h
\]

dove \(d\) è il diametro e \(h\) è l'altezza del cilindro. Gli errori associati al diametro \(d\) e all'altezza \(h\) vengono propagati per ottenere l'errore totale sul volume \(\sigma_V\). Successivamente, si propaga anche l'errore sulla pressione in funzione delle incertezze su \(T\) e \(V\).

## Obiettivi
1. Calcolare il volume del cilindro e la sua incertezza.
2. Calcolare la pressione usando la legge dei gas perfetti.
3. Propagare gli errori per determinare l'incertezza totale sulla pressione.

## Implementazione
Il codice è organizzato in diverse funzioni per modularità:

### 1. Funzione `calculate_volume`
Calcola il volume di un cilindro dato il diametro \(d\) e l'altezza \(h\):
```cpp
double calculate_volume(double d, double h);
```

### 2. Funzione `propagate_volume_error`
Calcola l'errore propagato sul volume:
```cpp
double propagate_volume_error(double d, double h, double sigma_d, double sigma_h);
```

### 3. Funzione `calculate_pressure`
Calcola la pressione secondo la legge dei gas perfetti:
```cpp
double calculate_pressure(double n, double T, double V);
```

### 4. Funzione `calculate_partials`
Calcola le derivate parziali della pressione rispetto alla temperatura \(T\) e al volume \(V\):
```cpp
std::vector<double> calculate_partials(double n, double T, double V, double delta = 1e-6);
```

### 5. Funzione `propagate_errors`
Propaga gli errori sulla pressione utilizzando le derivate parziali e gli errori di \(T\) e \(V\):
```cpp
double propagate_errors(double n, double T, double V, double sigma_T, double sigma_V);
```

### 6. Test con `doctest`
Il codice include un test per verificare i calcoli:
- Volume atteso del cilindro: \(V = 7.85398 \times 10^{-5} \ \text{m}^3\)
- Pressione attesa: \(p = 3174723.0 \ \text{Pa}\)
- Errore sulla pressione atteso: \(\sigma_p = 33856.7 \ \text{Pa}\)
