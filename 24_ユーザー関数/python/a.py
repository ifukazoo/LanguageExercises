#!/usr/bin/env python
# coding: -utf8

import anagram as a


if __name__ == '__main__':

    print("Enter two strings and I'll tell you if then are anagrams: ")
    first = input("Enter the first string: ")
    second = input("Enter the second string: ")

    ok = a.is_anagram(first, second)
    if ok:
        inverter = ""
    else:
        inverter = "not "

    print('"%s" and "%s" are %sanagrams.' % (first, second, inverter))
