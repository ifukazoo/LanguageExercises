#!/usr/bin/env python
# coding: -utf8

import sys
import karvonen as k


def read_user_input(prompter):
    while True:
        try:
            user_input = input(prompter)
            return int(user_input), False
        except EOFError:
            return 0, True
        except ValueError:
            print("Sorry. That's not a valid input.\n", end="")
            continue

def exit_by_eof():
    print("failed to read user input.\n", end="", file=sys.stderr)
    sys.exit(1)



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
    age, eof = read_user_input("Enter your age: ")
    if eof:
        exit_by_eof()

    resting_pulse, eof = read_user_input("Enter your resting pulse: ")
    if eof:
        exit_by_eof()

    print(title())
    print(separator())
    for intensity in range(55, 95 + 1, 5):
        rate = k.calc_heart_rate(age, resting_pulse, intensity)
        print(heart_rate_line(intensity, rate))
