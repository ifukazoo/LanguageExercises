#!/usr/bin/env python
# coding: -utf8

import enum
import string


PASSWORD_LENGHT_MIN = 8

Strength = enum.Enum("Strength", "VERY_WEAK  WEAK NORMAL STRONG VERY_STRONG")


def any_of(a, f):
    for c in a:
        if f(c):
            return True
    return False


def is_punct(s):
    return s in string.punctuation


def is_alpha(s):
    return s.isalpha()


def is_digit(s):
    return s.isdigit()


def password_validator(password):
    number_only = password.isdigit()
    letter_only = password.isalpha()
    contains_special = any_of(password, is_punct)
    contains_letter = any_of(password, is_alpha)
    contains_number = any_of(password, is_digit)
    too_short = len(password) < PASSWORD_LENGHT_MIN

    if too_short:
        if number_only:
            return Strength.VERY_WEAK
        elif letter_only:
            return Strength.WEAK
    else:
        if contains_letter and contains_number and contains_special:
            return Strength.VERY_STRONG
        if contains_letter and contains_number:
            return Strength.STRONG

    return Strength.NORMAL
