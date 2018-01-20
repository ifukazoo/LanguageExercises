#!/usr/bin/env python
# coding: -utf8

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


def validate_number(s):
    return int(s)


INVALID_MSG = "Sorry. That's not a valid input."

if __name__ == '__main__':

    age = ui.read_user_input_with_validator(
        "Enter your age: ", validate_number, INVALID_MSG)

    resting_pulse = ui.read_user_input_with_validator(
        "Enter your resting pulse: ", validate_number, INVALID_MSG)

    print(title())
    print(separator())
    for intensity in range(55, 95 + 1, 5):
        rate = k.calc_heart_rate(age, resting_pulse, intensity)
        print(heart_rate_line(intensity, rate))
