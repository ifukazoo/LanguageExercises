#include <cctype>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <numeric>

#include "functions.h"

typedef std::string String;
typedef std::vector<String> StringVector;
typedef StringVector::iterator StringVectorIt;
typedef std::map<String, String> StringMap;

inline String indefinite_article(String s)
{
  String b = "aiueoAIUEO";
  if (s.empty()) {
    return "";
  } else if (find(b.begin(), b.end(), s[0]) != b.end()) {
    return "an";
  }
  return "a";
}

struct GetInput {
  StringMap operator()(StringMap& result, String item) {
    String input;
    std::cout << "Enter "  << indefinite_article(item) << " " << item << ":";
    std::cin >> input;
    result.insert(make_pair(item, input));
    return result;
  }
};

int main()
{
  String items[] = {"adjective", "noun" , "verb", "adverb"};
  StringVector vector(items, items + array_length(items));

  StringMap answer_map;
  answer_map = accumulate(vector.begin(), vector.end(), answer_map, GetInput());
  String sep = "";
  for (StringVectorIt p =  vector.begin(); p != vector.end(); p++) {
    std::cout << sep << answer_map[*p];
    sep = " ";
  }
  std::cout << "." << std::endl;

  return 0;
}
