#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

std::vector<double> centralLimitTheorem(int N, int M) {
  std::default_random_engine gen;
  std::uniform_real_distribution<double> dis{0., 1.};

  std::vector<double> values(N);
  std::generate(values.begin(), values.end(), [M, &dis, &gen](){
		std::vector<double> v(M);
		std::fill(v.begin(), v.end(), dis(gen));
		std::generate(v.begin(), v.end(), [&dis, &gen](){ return dis(gen); });

		return std::accumulate(v.begin(), v.end(), 0.) / M;
	  });

  return values;
}

int main() {
  const std::vector<double> v{centralLimitTheorem(10000, 1000)};
  std::copy(v.begin(), v.end(), std::ostream_iterator<double>{std::cout, "\n"});
}
