#include <iostream>
#include <numeric>
#include <random>
#include <vector>

std::vector<double> clm(int N, int M) {
  std::mt19937 gen;
  std::uniform_real_distribution<double> dis{0., 1.};

  std::vector<double> values(N);
  for (int i{}; i < N; ++i) {
    std::vector<double> v(M);
    for (int j{}; j < M; ++j) {
      v[j] = dis(gen);
    }
    values[i] = std::accumulate(v.begin(), v.end(), 0.) / M;
  }

  return values;
}

int main() {
  std::vector<double> v{clm(10000, 1000)};
  for (auto const& x : v) {
    std::cout << x << '\n';
  }
}
