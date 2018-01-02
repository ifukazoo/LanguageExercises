#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    total = 0
    for i in range(5):
        user_input = input("Enter a number: ")
        num = int(user_input)
        total += num

    print(f"The total is {total}.\n", end='')
