#!/usr/bin/env python
# coding: -utf8

import user_input as ui


if __name__ == '__main__':
    rate, eof = ui.read_user_input("What is the rate of return? ")
    if eof:
        ui.exit_by_eof()

    years = int(72 / rate)
    print(
        f"It will take {years} years to double your initial investment.\n", end="")
