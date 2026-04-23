#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

std::vector<double> centralLimitTheorem(int N, int M) {
  assert(N > 0 && M > 0);

  std::default_random_engine gen;
  std::uniform_real_distribution<double> dis{0., 1.};

  std::vector<double> values;
  values.reserve(N);
  std::generate_n(std::back_inserter(values), N, [&]() {
    std::vector<double> v;
    v.reserve(M);
    std::generate_n(std::back_inserter(v), M, [&] { return dis(gen); });
    return std::accumulate(v.begin(), v.end(), 0.) / M;
  });

  return values;
}

int main() {
  auto const v = centralLimitTheorem(10000, 1000);
  std::copy(v.begin(), v.end(), std::ostream_iterator<double>{std::cout, "\n"});
}
