#!/usr/bin/env python
# coding: -utf8

import user_input as ui
import filter


def validate_num_vector(s):
    strings = s.split()
    numbers = []
    for s in strings:
        numbers.append(int(s))

    return numbers


if __name__ == '__main__':
    invalid_msg = "Sorry. That's not a valid input."
    numbers = ui.read_user_input_with_validator(
        "Enter a list of numbers, separated by spaces: ", validate_num_vector, invalid_msg)
    evens = filter.filter_even_numbers(numbers)
    print("The even numbers are", end="")
    for even in evens:
        print(f" {even}", end="")

    print(".")
