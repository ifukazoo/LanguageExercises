#!/usr/bin/env python
# coding: -utf8

import user_input as ui
import math
import functools


def validate_number_or_done(s):
    if s == "done":
        return s

    int(s)  # 例外がでないか試す.
    return s


def disp_nums(nums):
    print("Numbers: ", end="")
    sep = ""
    for i in nums:
        print(sep,  i, end="")
        sep = ","

    print("")


def average(nums):
    return sum(nums) / len(nums)


def standard_diviation(nums):
    ave = average(nums)
    tmp_sum = functools.reduce(lambda acc, e: acc + (ave - e) ** 2, nums, 0.0)
    variance = tmp_sum / len(nums)
    return math.sqrt(variance)


def round_pointn(d, n):
    multiplier = 1
    for i in range(n):
        multiplier *= 10
    d1 = d * multiplier
    d2 = round(d1)
    return d2 / multiplier


if __name__ == '__main__':
    nums = []
    while True:
        user_input = ui.read_user_input_with_validator(
            "Enter a number: ", validate_number_or_done,
            "Sorry. That's not a valid input.")
        if user_input == "done":
            break
        else:
            nums.append(int(user_input))

    if len(nums) != 0:
        disp_nums(nums)
        print(f"The average is {average(nums)}")
        print(f"The minimum is {min(nums)}")
        print(f"The maximum is {max(nums)}")
        print(
            f"The standard diviation is {round_pointn(standard_diviation(nums),2)}")
