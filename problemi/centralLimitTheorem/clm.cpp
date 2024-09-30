#include <cassert>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

std::vector<double> centralLimitTheorem(int N, int M) {
  assert(N > 0 && M > 0);

  std::default_random_engine gen;
  std::uniform_real_distribution<double> dis{0., 1.};

  std::vector<double> values;
  values.reserve(N);
  for (int i{}; i != N; ++i) {
    std::vector<double> v;
    v.reserve(M);
    for (int j{0}; j != M; ++j) {
      v.push_back(dis(gen));
    }
    values.push_back(std::accumulate(v.begin(), v.end(), 0.) / M);
  }

  return values;
}

int main() {
  auto const v = centralLimitTheorem(10000, 1000);
  for (auto const& x : v) {
    std::cout << x << '\n';
  }
}
