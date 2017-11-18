#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <cstdlib>
#include <cerrno>

#include <sstream>
#include <utility>
#include <algorithm>
#include <numeric>
#include <limits>

template<typename T, std::size_t SIZE>
inline std::size_t array_length(const T (&)[SIZE])
{
  return SIZE;
}
template<typename T>
std::string to_string(const T& value)
{
  std::ostringstream oss;
  oss << value;
  return oss.str();
}

#if 0
template<typename Numeric>
struct ston_result {
  typedef std::pair<bool, Numeric> type;
};

template<typename Float>
typename ston_result<Float>::type str_to_f(std::string s)
#endif
template<typename Float>
std::pair<bool, Float> str_to_f(std::string s)
{
  if (s.empty()) {
    return std::make_pair(false, 0);
  }

  char* endptr;
  errno = 0;
  double double_val = strtod(s.c_str(), &endptr);
  if (errno || *endptr) {
    return std::make_pair(false, 0);
  }
  bool toolarge = double_val >  std::numeric_limits<Float>::max();
  bool toosmall = double_val < -std::numeric_limits<Float>::max();
  if (toolarge || toosmall) {
    return std::make_pair(false, 0);
  }
  return std::make_pair(true, static_cast<Float>(double_val));
}

template<typename Integer>
std::pair<bool, Integer> str_to_i(std::string s)
{
  if (s.empty()) {
    return std::make_pair(false, 0);
  }

  char* endptr;
  errno = 0;
  long long_val = strtol(s.c_str(), &endptr, /*base*/10);
  if (errno || *endptr) {
    return std::make_pair(false, 0);
  }

  bool toolarge = long_val > std::numeric_limits<Integer>::max();
  bool toosmall = long_val < std::numeric_limits<Integer>::min();
  if (toolarge || toosmall) {
    return std::make_pair(false, 0);
  }
  return std::make_pair(true, static_cast<Integer>(long_val));
}

#endif

