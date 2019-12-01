#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    first_number = input('What is the first number? ')
    second_number = input('What is the second number? ')

    first_number = int(first_number)
    second_number = int(second_number)

    print("%d + %d = %d" %
        (first_number, second_number, first_number + second_number))
    print("%d - %d = %d" %
        (first_number, second_number, first_number - second_number))
    print("%d * %d = %d" %
        (first_number, second_number, first_number * second_number))
    print("%d / %d = %d" %
        (first_number, second_number, first_number / second_number))
