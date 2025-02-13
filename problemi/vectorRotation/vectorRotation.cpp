
#include <algorithm>
#include <cmath>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::vector<double> vectorRotation(const std::vector<double>& v, double theta) {
  const auto cosine = std::cos(theta);
  const auto sine = std::sin(theta);

  std::vector<std::vector<double>> rot_matrix{{cosine, -sine}, {sine, cosine}};
  std::vector<double> result(2);

  for (size_t i = 0; i < 2; ++i) {
    result[i] = rot_matrix[i][0] * v[0] + rot_matrix[i][1] * v[1];
  }

  return result;
}

// utility only used for testing
std::vector<double> negate(const std::vector<double>& vec) {
  std::vector<double> result(vec.size());
  for (size_t i = 0; i < vec.size(); ++i) {
    result[i] = -vec[i];
  }
  return result;
}

TEST_CASE("Test rotation of versors") {
  const std::vector<double> i{1, 0};
  const std::vector<double> j{0, 1};
  const auto i_90 = vectorRotation(i, M_PI / 2);
  const auto j_90 = vectorRotation(j, M_PI / 2);

  auto Equality = [](double x, double y) -> bool { return std::abs(x - y) < 1e-5; };
  bool eq1 = std::equal(i_90.begin(), i_90.end(), j.begin(), Equality);
  CHECK(eq1);
  bool eq2 = std::equal(j_90.begin(), j_90.end(), negate(i).begin(), Equality);
  CHECK(eq2);
}

TEST_CASE("Test vector rotation") {
  const std::vector<double> v{1, 1};
  const std::vector<double> v_90 = {-1, 1};
  const std::vector<double> v_180 = {-1, -1};
  const std::vector<double> v_270 = {1, -1};
  const std::vector<double> v_360 = v;

  const auto result = vectorRotation(v, M_PI / 2);
  const auto result2 = vectorRotation(v, M_PI);
  const auto result3 = vectorRotation(v, 3 * M_PI / 2);
  const auto result4 = vectorRotation(v, 2 * M_PI);

  auto Equality = [](double x, double y) -> bool { return std::abs(x - y) < 1e-5; };
  bool eq1 = std::equal(result.begin(), result.end(), v_90.begin(), Equality);
  CHECK(eq1);
  bool eq2 = std::equal(result2.begin(), result2.end(), v_180.begin(), Equality);
  CHECK(eq2);
  bool eq3 = std::equal(result3.begin(), result3.end(), v_270.begin(), Equality);
  CHECK(eq3);
  bool eq4 = std::equal(result4.begin(), result4.end(), v_360.begin(), Equality);
  CHECK(eq4);
}
