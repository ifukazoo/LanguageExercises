#include <cstdlib>
#include <iostream>
#include <string>
#include "anagram.h"

using String = std::string;

String surround_string(const String& s)
{
  return "\"" + s + "\"";
}

int main()
{
  String first, second;
  std::cout << "Enter two strings and I'll tell you if then are anagrams: " << std::endl;
  std::cout << "Enter the first string: ";
  std::cin >> first;
  std::cout << "Enter the second string: ";
  std::cin >> second;
  bool anagram = is_anagram(first, second);
  std::cout << surround_string(first)
    << " and "
    << surround_string(second)
    << " are "
    << (!anagram ? "not " : "")
    << "anagrams"
    << std::endl;

  return EXIT_SUCCESS;
}

