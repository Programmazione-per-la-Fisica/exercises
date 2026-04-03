#include <sstream>

#include "boltzmann/boltzmann.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE(
    "Test total energy conservation and that energies are always positive") {
  int molecules{1000};
  int n_interactions{100000};
  double kBT{2.0};
  double hparam{10.0};
  std::default_random_engine gen;

  double initial_energy{molecules * 1.5 * kBT};
  BoltzmannSimulator sim{molecules, gen, kBT, hparam};
  sim.run(n_interactions);

  double final_energy{0.0};

  for (double e : sim.get_energies()) {
    final_energy += e;
    CHECK(e >= 0.0);
  }
  CHECK(final_energy == doctest::Approx(initial_energy).epsilon(1e-9));
}