#include <algorithm>
#include <functional>
#include <limits>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

template <typename F1, typename F2>
double minFunctionDistance(F1 f1, F2 f2) {
  std::vector<double> v(101);
  const double delta{0.125};
  std::generate(v.begin() + 1, v.end(),
                [n = 0., delta]() mutable { return n += delta; });

  double distance{std::numeric_limits<double>::max()};
  for (auto const& x : v) {
    double partial_distance{std::abs(f1(x) - f2(x))};

    if (partial_distance < distance) {
      distance = partial_distance;
    }
  }

  return distance;
}

TEST_CASE("Testing the function") {
  CHECK(doctest::Approx(minFunctionDistance([](double x) { return x; },
                                            [](double x) { return x * x; }))
            .epsilon(0.01) == 0.);
  CHECK(doctest::Approx(minFunctionDistance([](double x) { return x + 3; },
                                            [](double x) { return x + 4; }))
            .epsilon(0.01) == 1.);
  CHECK(doctest::Approx(minFunctionDistance([](double x) { return 2 * x + 1; },
                                            [](double x) { return x; }))
            .epsilon(0.01) == 1.);
  CHECK(doctest::Approx(minFunctionDistance([](double x) { return 1.; },
                                            [](double x) { return x; }))
            .epsilon(0.01) == 0.);
  CHECK(doctest::Approx(minFunctionDistance([](double x) { return x; },
                                            [](double x) { return x; }))
            .epsilon(0.01) == 0.);
}
