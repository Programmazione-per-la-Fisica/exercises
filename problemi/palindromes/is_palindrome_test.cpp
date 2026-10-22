#include <string>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

bool is_palindrome(std::vector<int> const& v) {
  long int const n{std::ssize(v)};

  for (long int i{0}; i != n / 2; ++i) {
    if (v[i] != v[n - 1 - i]) {
      return false;
    }
  }

  return true;
}

bool is_palindrome(std::string const& s) {
  long int const n{std::ssize(s)};

  for (long int i{0}; i != n / 2; ++i) {
    if (s[i] != s[n - 1 - i]) {
      return false;
    }
  }

  return true;
}

TEST_CASE("Test vector is_palindrome, successful cases") {
  std::vector<int> v_zero;
  CHECK(is_palindrome(v_zero));

  std::vector<int> v_one{20};
  CHECK(is_palindrome(v_one));

  std::vector<int> v_odd{18, 84, 142, 84, 18};
  CHECK(is_palindrome(v_odd));

  std::vector<int> v_even{20, 45, 84, 142, 142, 84, 45, 20};
  CHECK(is_palindrome(v_even));
}

TEST_CASE("Test vector is_palindrome, failures") {
  std::vector<int> v_odd{18, 84, 299, 142, 18};
  CHECK(!is_palindrome(v_odd));

  std::vector<int> v_even{1, 5, 10, 100, 1000};
  CHECK(!is_palindrome(v_even));
}

TEST_CASE("Test string is_palindrome, successful cases") {
  std::string s_zero;
  CHECK(is_palindrome(s_zero));

  std::string s_one{'B'};
  CHECK(is_palindrome(s_one));

  std::string s_odd{"ovattavo"};
  CHECK(is_palindrome(s_odd));

  std::string s_even{"radar"};
  CHECK(is_palindrome(s_even));
}

TEST_CASE("Test string is_palindrome, failures") {
  std::string v_odd{"prole"};
  CHECK(!is_palindrome(v_odd));

  std::string v_even{"parole"};
  CHECK(!is_palindrome(v_even));
}