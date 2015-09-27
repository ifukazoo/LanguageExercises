#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <string>
#include <iostream>
#include <numeric>
#include <limits>

typedef std::string String;

struct IsDigit : public std::binary_function<bool, char, bool> {
  bool operator() (bool result, char c) {
    return !result ? result : (isdigit(c) > 0);
  }
};

template<typename Integer>
std::pair<bool, Integer> string_to_integer(String s)
{
  if (s.empty()) {
    return std::make_pair(false, 0);
  }

  String::iterator start =
    (s[0] == '+' || s[0] == '-')
    ? s.begin() + 1
    : s.begin();

  if (!accumulate(start, s.end(), true, IsDigit())) {
    return std::make_pair(false, 0);
  }

  errno = 0;
  long long_val = strtol(s.c_str(), NULL, /*base*/10);
  if (errno) {
    return std::make_pair(false, 0);
  }

  bool toolarge = long_val > std::numeric_limits<Integer>::max();
  bool toosmall = long_val < std::numeric_limits<Integer>::min();
  if (toolarge || toosmall) {
    return std::make_pair(false, 0);
  }
  return std::make_pair(true, static_cast<Integer>(long_val));
}


int main()
{
  long first, second;
  String first_in, second_in;
  while (true) {
    std::cout << "What is the first number? ";
    std::cin >> first_in;
    std::cout << "What is the second number? ";
    std::cin >> second_in;

    std::pair<bool, long> result_first = string_to_integer<long>(first_in);
    if (!result_first.first) {
      std::cout << "illegal first number" << std::endl;
      continue;
    }
    std::pair<bool, long> result_second = string_to_integer<long>(second_in);
    if (!result_second.first) {
      std::cout << "illegal second number" << std::endl;
      continue;
    }
    first = result_first.second;
    second = result_second.second;
    break;
  }

  std::cout << first << " + " << second << " = " << first + second << std::endl;
  std::cout << first << " - " << second << " = " << first - second << std::endl;
  std::cout << first << " * " << second << " = " << first * second << std::endl;
  std::cout << first << " / " << second << " = " << first / second << std::endl;

  return 0;
}
