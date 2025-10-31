# Carnot cycle efficiency

The Carnot cycle is a theoretical thermodynamic cycle that provides the maximum possible efficiency for a heat engine operating between two temperature reservoirs. It consists of two reversible isothermal processes (one at a high temperature $T_h$ and one at a low temperature $T_l$ and two reversible adiabatic processes. The efficiency $\eta$ of a Carnot cycle is given by the formula:
$$ \eta = 1 - \frac{T_l}{T_h} $$
The above formula can be derived from the more general definition of efficiency for a heat engine:
$$ \eta = \frac{W}{Q_{abs}} $$
where $W$ is the work done by the engine and $Q_{abs}$ is the heat absorbed from the high-temperature reservoir.

## Objective

Write a program that calculates the efficiency of the Carnot cycle, computing $W$ and $Q$ for all the transformations involved in the cycle. *You can assume the working substance is 1 mole of ideal monoatomic gas.*

The program should take as input the following thermodynamic variables:

- Temperature of the high-temperature reservoir $T_h$;
- Temperature of the low-temperature reservoir $T_l$;
- Initial volume of the $T_h$ isothermal expansion $V_A$;
- Final volume of the $T_h$ isothermal expansion $V_B = 10\cdot V_A$;

and compare the efficiency of the cycle computed both using the Carnot formula and using the work and heat calculations.

**Bonus:** Show that the efficiency does not depend on the initial volume $V_A$.

**Bonus 2:** Implement a variable number of thermodynamic steps in each transformation, and show that the efficiency converges to the Carnot efficiency as the number of steps increases.

## Hints

- For an isothermal transformation of an ideal gas, the work done by the gas is given by:
  $$ W_{isothermal} = nRT \ln\left(\frac{V_f}{V_i}\right) $$
  where $n$ is the number of moles, $R$ is the ideal gas constant, $T$ is the temperature, and $V_i$ and $V_f$ are the initial and final volumes, respectively.
  
  The heat absorbed or released during an isothermal process is equal to the work done:
  $$ Q_{isothermal} = W_{isothermal} $$

- For an adiabatic transformation of an ideal monoatomic gas, the Poisson relation holds:
  $$ PV^\gamma = \text{constant} $$
  where $\gamma = \frac{C_p}{C_v} = \frac{5}{3}$ for a monoatomic ideal gas.
