#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    import sys

    user_input = input("Enter the first number: ")
    first_number = int(user_input)

    user_input = input("Enter the second number: ")
    second_number = int(user_input)

    user_input = input("Enter the third number: ")
    third_number = int(user_input)

    if first_number == second_number or first_number == third_number or second_number == third_number:
        exit()

    max_number = -sys.maxsize
    if max_number < first_number:
        max_number = first_number
    if max_number < second_number:
        max_number = second_number
    if max_number < third_number:
        max_number = third_number

    print(f"The largest number is {max_number}.")
