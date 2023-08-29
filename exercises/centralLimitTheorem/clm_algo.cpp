#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

std::vector<double> centralLimitTheorem(int N, int M) {
  std::default_random_engine gen;
  std::uniform_real_distribution<double> dis{0., 1.};

  std::vector<double> values(N);
  std::for_each(values.begin(), values.end(), [M, &dis, &gen](auto& x){
		std::vector<double> v(M);
		std::fill(v.begin(), v.end(), dis(gen));

		x = std::accumulate(v.begin(), v.end(), 0.) / M;
	  });

  return values;
}

int main() {
  std::vector<double> v{centralLimitTheorem(10000, 1000)};
  for (auto const& x : v) {
    std::cout << x << '\n';
  }
}
