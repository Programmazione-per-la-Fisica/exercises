#ifndef BOLTZMANN_H
#define BOLTZMANN_H

#include <random>

struct SimStats {
  double mean;
  double stddev;
};

class BoltzmannSimulator {
  int molecules_;
  double deltaU_;
  std::vector<double> energies_;

  std::default_random_engine& gen_;
  std::uniform_int_distribution<int> dist_;

  void transfer_step();

 public:
  BoltzmannSimulator(int molecules, std::default_random_engine& gen, double kBT,
                     double hparam);

  void run(int n_interactions);
  const std::vector<double>& get_energies() const { return energies_; }
  SimStats get_stats() const;
};

#endif