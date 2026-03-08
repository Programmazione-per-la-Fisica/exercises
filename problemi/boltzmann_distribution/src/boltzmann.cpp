#include "boltzmann/boltzmann.h"

BoltzmannSimulator::BoltzmannSimulator(int molecules,
                                       std::default_random_engine &gen,
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
  for (int i{0}; i != n_interactions; ++i) {
    transfer_step();
  }
}

SimStats BoltzmannSimulator::get_stats() const {
  SimStats s{0., 0.};
  double sum{0.};
  double sum2{0.};
  for (double e : energies_) {
    sum += e;
    sum2 += e * e;
  }
  s.mean = sum / molecules_;
  s.stddev = std::sqrt(sum2 / molecules_ - s.mean * s.mean);
  return s;
}