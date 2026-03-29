#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cassert>
#include <cmath>
#include <stdexcept>

#include "doctest.h"

constexpr double R{8.314};
constexpr double gamma_mono{5. / 3};  // Per un gas monoatomico

class State {
  double V_;
  double T_;

 public:
  State(double V, double T) : V_(V), T_(T) {
    if (V <= 0) {
      throw std::runtime_error("Volume must be positive and non-zero");
    }
    if (T <= 0) {
      throw std::runtime_error("Temperature must be positive and non-zero");
    }
  }

  double V() const { return V_; }
  double T() const { return T_; }
  double P() const { return (R * T_) / V_; }  // Legge dei gas ideali
  void set_T(double T) { T_ = T; }
  void set_V(double V) { V_ = V; }
};

double trapezoidal_integration(double dx, double f0, double f1) {
  return 0.5 * dx * (f0 + f1);
}

double isothermal_work(const State& state1, const State& state2, int N) {
  if (N <= 0) {
    throw std::runtime_error("N must be positive and non-zero");
  }
  double dV{(state2.V() - state1.V()) / N};
  double work{0.0};

  State temp_state{state1};

  for (int i = 0; i < N; ++i) {
    double V2_step{temp_state.V() + dV};
    double P2_step{(R * state1.T()) / V2_step};

    work += trapezoidal_integration(dV, temp_state.P(), P2_step);
    temp_state.set_V(V2_step);
  }
  return work;
}

double adiabatic_work(const State& state1, const State& state2, int N) {
  if (N <= 0) {
    throw std::runtime_error("N must be positive and non-zero");
  }
  double dV{(state2.V() - state1.V()) / N};
  double work{0.0};
  const double C{R * state1.T() * std::pow(state1.V(), gamma_mono - 1)};

  State temp_state{state1};

  for (int i = 0; i < N; ++i) {
    double V2_step{temp_state.V() + dV};
    double P2_step{C / std::pow(V2_step, gamma_mono)};
    work += trapezoidal_integration(dV, temp_state.P(), P2_step);
    temp_state.set_V(V2_step);
    temp_state.set_T(C / (R * std::pow(V2_step, gamma_mono - 1)));
  }
  return work;
}

TEST_CASE("Isothermal work correctness") {
  double T{300.0};
  State A{0.01, T};
  State B{10 * A.V(), T};
  int N{1000};

  double W_analytical{R * T *
                      std::log(B.V() / A.V())};  // Lavoro isoterma ideale
  double W_num{isothermal_work(A, B, N)};

  CHECK(std::abs(W_num - W_analytical) / std::abs(W_analytical) < 1e-4);
}

TEST_CASE("Adiabatic work correctness") {
  double Th{500.0};
  double Tl{300.0};
  State A{0.01, Th};
  State B{A.V() * std::pow(Th / Tl, 1.0 / (gamma_mono - 1)), Tl};
  int N{1000};

  double W_analytical{
      (3. / 2) * R *
      (Th - Tl)};  // Ottenuta dal primo principio della termodinamica
  double W_num{adiabatic_work(A, B, N)};

  CHECK(std::abs(W_num - W_analytical) / std::abs(W_analytical) < 1e-4);
}

TEST_CASE("Negative volume or temperature") {
  CHECK_THROWS(State(-0.01, 300.0));
  CHECK_THROWS(State(0.01, -300.0));
}

TEST_CASE("Integration error handling") {
  double T{300.0};
  State A{0.01, T};
  State B{10 * A.V(), T};

  CHECK_THROWS(isothermal_work(A, B, 0));
  CHECK_THROWS(isothermal_work(A, B, -10));
  CHECK_THROWS(adiabatic_work(A, B, 0));
  CHECK_THROWS(adiabatic_work(A, B, -10));
}

TEST_CASE("Carnot efficiency comparison") {
  const double Th{700.0};    // Temperatura alta in K
  const double Tl{300.0};    // Temperatura bassa in K
  const double Va{0.01};     // Volume stato A
  const double Vb{10 * Va};  // Volume stato B

  double Vc{Vb * std::pow(Th / Tl, 1.0 / (gamma_mono - 1))};
  double Vd{Va * std::pow(Th / Tl, 1.0 / (gamma_mono - 1))};

  State A{Va, Th};
  State B{Vb, Th};
  State C{Vc, Tl};
  State D{Vd, Tl};

  SUBCASE("Efficiency not dependent of initial volume") {
    int N{1000};
    double W_ab1{isothermal_work(A, B, N)};
    double W_bc1{adiabatic_work(B, C, N)};
    double W_cd1{isothermal_work(C, D, N)};
    double W_da1{adiabatic_work(D, A, N)};

    State A2{2 * Va, Th};   // Cambiamento volume iniziale
    State B2{20 * Va, Th};  // Mantengo lo stesso rapporto Vb/Va

    Vc = B2.V() * std::pow(Th / Tl, 1.0 / (gamma_mono - 1));
    Vd = A2.V() * std::pow(Th / Tl, 1.0 / (gamma_mono - 1));

    State C2{Vc, Tl};
    State D2{Vd, Tl};

    double W_ab2{isothermal_work(A2, B2, N)};
    double W_bc2{adiabatic_work(B2, C2, N)};
    double W_cd2{isothermal_work(C2, D2, N)};
    double W_da2{adiabatic_work(D2, A2, N)};

    double eta_num1{(W_ab1 + W_bc1 + W_cd1 + W_da1) / W_ab1};
    double eta_num2{(W_ab2 + W_bc2 + W_cd2 + W_da2) / W_ab2};

    CHECK(std::abs(eta_num1 - eta_num2) < 1e-6);
  }

  SUBCASE("Carnot efficiency for small N") {
    int N{10};
    double W_ab{isothermal_work(A, B, N)};
    double W_bc{adiabatic_work(B, C, N)};
    double W_cd{isothermal_work(
        C, D,
        N / 3)};  // Diversificato N per rompere simmetria nell'integrazione
    double W_da{adiabatic_work(D, A, N)};

    // Il calore viene scambiato solo nelle trasformazioni isoterme. Pertanto
    // Qabs = W_ab
    double eta_num{(W_ab + W_bc + W_cd + W_da) / W_ab};
    double eta_carnot{1.0 - (Tl / Th)};

    CHECK_FALSE(std::abs(eta_num - eta_carnot) < 1e-4);
  }

  SUBCASE("Carnot efficiency for large N") {
    int N{1000};
    double W_ab{isothermal_work(A, B, N)};
    double W_bc{adiabatic_work(B, C, N)};
    double W_cd{isothermal_work(
        C, D,
        N / 3)};  // Diversificato N per rompere simmetria nell'integrazione
    double W_da{adiabatic_work(D, A, N)};

    // Il calore viene scambiato solo nelle trasformazioni isoterme. Pertanto
    // Qabs = W_ab
    double eta_num{(W_ab + W_bc + W_cd + W_da) / W_ab};
    double eta_carnot{1.0 - (Tl / Th)};

    CHECK(std::abs(eta_num - eta_carnot) < 1e-4);
  }
}