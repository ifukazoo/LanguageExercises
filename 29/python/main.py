#!/usr/bin/env python
# coding: -utf8

import user_input as ui


def validate_rate(s):
    rate = int(s)
    if rate == 0:
        raise ValueError
    return rate


if __name__ == '__main__':
    rate = ui.read_user_input_with_validator(
        "What is the rate of return? ", validate_rate,  "Sorry. That's not a valid input.")

    years = int(72 / rate)
    print(
        f"It will take {years} years to double your initial investment.")
