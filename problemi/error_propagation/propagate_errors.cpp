#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cmath>
#include <iostream>
#include <numbers>
#include <vector>

#include "doctest.h"

double constexpr R{8.314};

double constexpr calculate_volume(double const d, double const h) {
  return (M_PI / 4.) * std::pow(d, 2) * h;
}

double constexpr propagate_volume_error(double const d, double const h,
                                        double const sigma_d,
                                        double const sigma_h) {
  double partial_d = (M_PI / 2.) * d * h;
  double partial_h = (M_PI / 4.) * std::pow(d, 2);

  double sigma_squared =
      std::pow(partial_d * sigma_d, 2) + std::pow(partial_h * sigma_h, 2);
  return std::sqrt(sigma_squared);
}

double constexpr calculate_pressure(double n, double T, double V) {
  return (n * R * T) / V;
}

std::vector<double> calculate_partials(double const n, double const T,
                                       double const V,
                                       double const delta = 1e-6) {
  std::vector<double> partials(2);

  double pressure_plus_T = calculate_pressure(n, T + delta, V);
  double pressure_minus_T = calculate_pressure(n, T - delta, V);
  partials[0] = (pressure_plus_T - pressure_minus_T) / (2 * delta);

  double pressure_plus_V = calculate_pressure(n, T, V + delta);
  double pressure_minus_V = calculate_pressure(n, T, V - delta);
  partials[1] = (pressure_plus_V - pressure_minus_V) / (2 * delta);

  return partials;
}

double propagate_errors(double n, double T, double V, double sigma_T,
                        double sigma_V) {
  const std::vector<double> partials{calculate_partials(n, T, V)};

  double sigma_squared{std::pow(partials[0] * sigma_T, 2) +
                       std::pow(partials[1] * sigma_V, 2)};
  return std::sqrt(sigma_squared);
}

TEST_CASE("Propagazione degli errori") {
  double constexpr n{1.0};           // [mol]
  double constexpr T{300.0};         // [K]
  double constexpr d{0.1};           // [m]
  double constexpr h{0.01};          // [m]
  double constexpr sigma_d{0.001};   // [m]
  double constexpr sigma_h{0.0001};  // [m]

  auto V = calculate_volume(d, h);
  auto sigma_V = propagate_volume_error(d, h, sigma_d, sigma_h);

  double constexpr sigma_T = 1.0;  // [K]

  auto calculated_pressure = calculate_pressure(n, T, V);
  auto propagated_error = propagate_errors(n, T, V, sigma_T, sigma_V);

  CHECK(doctest::Approx(V).epsilon(1) == 7.85398e-5);
  CHECK(doctest::Approx(calculated_pressure).epsilon(1) == 3174723.0);
  CHECK(doctest::Approx(propagated_error).epsilon(1) == 33856.7);
}
