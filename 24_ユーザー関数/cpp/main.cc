#include <iostream>

#include "./anagram.h"

inline static std::string surround_dq(std::string s)
{
    return "\"" + s + "\"";
}

int main()
{
    std::string first, second;

    std::cout << "Enter two strings and I'll tell you if then are anagrams: " << std::endl;

    std::cout << "Enter the first string: ";
    std::getline(std::cin, first);

    std::cout << "Enter the second string: ";
    std::getline(std::cin, second);

    bool anagram = is_anagram(first, second);
    std::cout
        << surround_dq(first)
        << " and "
        << surround_dq(second)
        << " are "
        << (anagram ? "" : "not ")
        << "anagrams."
        << std::endl;

    return 0;
}

