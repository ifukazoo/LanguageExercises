#!/usr/bin/env python
# coding: -utf8

import sys
import user_input as ui


if __name__ == '__main__':
    invalid_msg = "Sorry. That's not a valid input."

    while True:
        rate, eof = ui.read_user_input(
            "What is the rate of return? ", invalid_msg)
        if eof:
            sys.exit(1)

        if rate == 0:
            print(invalid_msg)
            continue
        else:
            break

    years = int(72 / rate)
    print(
        f"It will take {years} years to double your initial investment.")
