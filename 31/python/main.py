#!/usr/bin/env python
# coding: -utf8

import sys
import user_input as ui
import karvonen as k


def partition_format(left, right):
    return left + "|" + right


def title():
    return partition_format("Intensity\t", " Rate")


def separator():
    return partition_format("----------------", "----------")


def heart_rate_line(intensity, rate):
    left = "%d%%\t\t" % intensity
    right = " %d bpm" % rate
    return partition_format(left, right)


if __name__ == '__main__':
    invalid_msg = "Sorry. That's not a valid input."

    age, eof = ui.read_user_input("Enter your age: ", invalid_msg)
    if eof:
        sys.exit(1)

    resting_pulse, eof = ui.read_user_input("Enter your resting pulse: ",invalid_msg)
    if eof:
        sys.exit(1)

    print(title())
    print(separator())
    for intensity in range(55, 95 + 1, 5):
        rate = k.calc_heart_rate(age, resting_pulse, intensity)
        print(heart_rate_line(intensity, rate))
