#include <algorithm>
#include <functional>
#include <limits>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

using func_t = std::function<double(double)>;

double minFunctionDistance_1(func_t f1, func_t f2) {
  std::vector<double> v(101);
  std::vector<double> distances(101);

  // Generate the x values
  double n{0.};
  std::generate(v.begin()+1, v.end(), [&n]() { return n += 0.1; });
  // Calculate the distance for each x value
  std::transform(v.begin(), v.end(), distances.begin(), [f1, f2](auto x) {
		return std::abs(f1(x) - f2(x));
	  });

  return *std::min_element(distances.begin(), distances.end());
}

double minFunctionDistance_2(func_t f1, func_t f2) {
  std::vector<double> v(101);
  std::vector<double> distances(101);

  double n{0.};
  std::generate(v.begin(), v.end(), [f1, f2, &n]() { 
	  double dist{std::abs(f1(n) - f2(n))};
	  n += 0.1;
	  return dist;
	  });

  return *std::min_element(v.begin(), v.end());
}

TEST_CASE("Testing the function 1") {
  CHECK(doctest::Approx(minFunctionDistance_1([](double x) { return x; },
                            [](double x) { return x * x; })).epsilon(0.01) == 0.);
  CHECK(doctest::Approx(minFunctionDistance_1([](double x) { return x + 3; },
                            [](double x) { return x + 4; })).epsilon(0.01) == 1.);
  CHECK(doctest::Approx(minFunctionDistance_1([](double x) { return 2*x + 1; },
                            [](double x) { return x; })).epsilon(0.01) == 1.);
}

TEST_CASE("Testing the function 2") {
  CHECK(doctest::Approx(minFunctionDistance_2([](double x) { return x; },
                            [](double x) { return x * x; })).epsilon(0.01) == 0.);
  CHECK(doctest::Approx(minFunctionDistance_2([](double x) { return x + 3; },
                            [](double x) { return x + 4; })).epsilon(0.01) == 1.);
  CHECK(doctest::Approx(minFunctionDistance_2([](double x) { return 2*x + 1; },
                            [](double x) { return x; })).epsilon(0.01) == 1.);
}
