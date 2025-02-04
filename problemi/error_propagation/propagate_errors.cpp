#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cmath>
#include <numbers>

#include "doctest.h"

constexpr double R{8.314};

double calculate_volume(double d, double h) {
  return (std::numbers::pi / 4.) * d * d * h;
}

double propagate_volume_error(double d, double h, double sigma_d,
                              double sigma_h) {
  auto partial_d = (std::numbers::pi / 2.) * d * h;
  auto partial_h = (std::numbers::pi / 4.) * d * d;

  auto sigma_squared =
      std::pow(partial_d * sigma_d, 2) + std::pow(partial_h * sigma_h, 2);
  return std::sqrt(sigma_squared);
}

double calculate_pressure(double n, double T, double V) {
  return n * R * T / V;
}

struct Partials {
  double dp_over_dT;
  double dp_over_dV;
};

Partials calculate_partials(double n, double T, double V, double delta = 1e-6) {
  auto pressure_plus_T = calculate_pressure(n, T + delta, V);
  auto pressure_minus_T = calculate_pressure(n, T - delta, V);
  auto dp_over_dT = (pressure_plus_T - pressure_minus_T) / (2 * delta);

  auto pressure_plus_V = calculate_pressure(n, T, V + delta);
  auto pressure_minus_V = calculate_pressure(n, T, V - delta);
  auto dp_over_dV = (pressure_plus_V - pressure_minus_V) / (2 * delta);

  return {dp_over_dT, dp_over_dV};
}

double propagate_errors(double n, double T, double V, double sigma_T,
                        double sigma_V) {
  auto partials{calculate_partials(n, T, V)};

  auto sigma_squared{std::pow(partials.dp_over_dT * sigma_T, 2) +
                     std::pow(partials.dp_over_dV * sigma_V, 2)};
  return std::sqrt(sigma_squared);
}

TEST_CASE("Propagazione degli errori") {
  constexpr double n{1.0};           // [mol]
  constexpr double T{300.0};         // [K]
  constexpr double sigma_T{1.0};     // [K]
  constexpr double d{0.1};           // [m]
  constexpr double sigma_d{0.001};   // [m]
  constexpr double h{0.01};          // [m]
  constexpr double sigma_h{0.0001};  // [m]

  auto V = calculate_volume(d, h);
  auto sigma_V = propagate_volume_error(d, h, sigma_d, sigma_h);

  auto calculated_pressure = calculate_pressure(n, T, V);
  auto propagated_error = propagate_errors(n, T, V, sigma_T, sigma_V);

  CHECK(doctest::Approx(V).epsilon(1) == 7.85398e-5);
  CHECK(doctest::Approx(calculated_pressure).epsilon(1) == 3174723.0);
  CHECK(doctest::Approx(propagated_error).epsilon(1) == 33856.7);
}
