#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <cstdlib>
#include <cerrno>

#include <algorithm>
#include <numeric>
#include <limits>

struct IsDigit : public std::binary_function<bool, char, bool> {
  bool operator() (bool result, char c) {
    return !result ? result : (isdigit(c) > 0);
  }
};

struct IsDigitOrPoint : public std::binary_function<bool, char, bool> {
  bool operator() (bool result, char c) {
    return !result ? result : (isdigit(c) > 0 || c == '.');
  }
};

template<typename T, std::size_t SIZE>
inline std::size_t array_length(const T (&)[SIZE])
{
  return SIZE;
}

template<typename Integer>
std::pair<bool, Integer> string_to_integer(std::string s)
{
  if (s.empty()) {
    return std::make_pair(false, 0);
  }

  std::string::iterator start =
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

template<typename Float>
std::pair<bool, Float> str_to_f(std::string s)
{
  if (s.empty()) {
    return std::make_pair(false, 0);
  }

  char* endptr;
  errno = 0;
  double double_val = strtod(s.c_str(), &endptr);
  if (errno || *endptr != '\0') {
    return std::make_pair(false, 0);
  }
  bool toolarge = double_val >  std::numeric_limits<Float>::max();
  bool toosmall = double_val < -std::numeric_limits<Float>::max();
  if (toolarge || toosmall) {
    return std::make_pair(false, 0);
  }
  return std::make_pair(true, static_cast<Float>(double_val));
}

#endif

