#!/usr/bin/env python
# coding: -utf8


def show_error_msg():
    print("Sorry. That's not a valid input.\n", end="")


if __name__ == '__main__':
    while True:
        user_input = input("What is the rate of return? ")
        try:
            rate = int(user_input)
            if rate == 0:
                show_error_msg()
                continue

            years = int(72 / rate)
            print(
                f"It will take {years} years to double your initial investment.\n", end="")
            break

        except ValueError:
            show_error_msg()
            continue
