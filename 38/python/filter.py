#!/usr/bin/env python
# coding: -utf8

def filter_even_numbers(numbers):
    evens = []
    for n in numbers:
        if n % 2 == 0:
            evens.append(n)
    return evens
