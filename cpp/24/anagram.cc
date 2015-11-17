#include "anagram.h"

bool is_anagram(const std::string& lhs, const std::string& rhs)
{
  if (lhs.length() != rhs.length()) {
    return false;
  }
  std::string::const_iterator it = lhs.begin();
  for (;it != lhs.end(); it++) {
    if (rhs.find(*it) == std::string::npos) {
      return false;
    }
  }
  return true;
}
