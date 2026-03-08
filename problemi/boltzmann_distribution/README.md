# Boltzmann Distribution simulation

This project simulates the evolution of an N molecules system, all with the same initial energy equal to ($3/2 k_BT$)J:

- At each interaction, a randomly-chosen molecule transfers a quantum of energy $\Delta U = (k_BT)/h$ J to another randomly-chosen molecule. $h\approx 10$.
- After each interaction, a histogram shows the energy distribution of the molecules.

The number of molecules and the number of interactions are user-defined parameters. $k_B T$ and $h$ are fixed by default to 2.0 and 10.0, respectively, but they can be set by the user.

## Usage

```bash
boltzmann_distribution <num_molecules> <interactions [list comma separated]> 
```

for example:

```bash
boltzmann_distribution 1000 1000,10000,100000
```

## Plotting

Two possible plotting solutions are provided:

- Plain ASCII plotting, output to `stdout` and/or file;
- ROOT-based plotting (requires ROOT installed).
