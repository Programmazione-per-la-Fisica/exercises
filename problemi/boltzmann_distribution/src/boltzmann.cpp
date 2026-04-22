#include "boltzmann/boltzmann.h"

#include <cassert>

BoltzmannSimulator::BoltzmannSimulator(int molecules,
                                       std::default_random_engine& gen,
                                       double kBT, double hparam)
    : molecules_{molecules},
      deltaU_{kBT / hparam},
      energies_(molecules, 1.5 * kBT),
      gen_{gen},
      dist_{0, molecules - 1} {}

void BoltzmannSimulator::transfer_step() {
  int i{dist_(gen_)};
  int j{dist_(gen_)};
  if (energies_[i] >= deltaU_) {
    energies_[i] -= deltaU_;
    energies_[j] += deltaU_;
  }
}

void BoltzmannSimulator::run(int n_interactions) {
  assert(n_interactions >= 0);
  for (int i{0}; i != n_interactions; ++i) {
    transfer_step();
  }
}

SimStats BoltzmannSimulator::get_stats() const {
  double sum{0.};
  double sum2{0.};
  for (auto& e : energies_) {
    sum += e;
    sum2 += e * e;
  }
  return {sum / molecules_, std::sqrt(sum2 / molecules_ -
                                      (sum / molecules_) * (sum / molecules_))};
}