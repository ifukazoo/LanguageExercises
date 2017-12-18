#!/usr/bin/env python
# coding: -utf8

import validator as p


def strength_to_string(strength):
    switcher = {
        p.Strength.VERY_WEAK: "very weak",
        p.Strength.WEAK: "weak",
        p.Strength.NORMAL: "normal",
        p.Strength.STRONG: "strong",
        p.Strength.VERY_STRONG: "very strong",
    }
    return switcher[strength]


def output(password):
    strength = p.password_validator(password)
    print(
        f"The password '{password}' is a {strength_to_string(strength)} password.")


if __name__ == '__main__':
    output("12345")
    output("abcdef")
    output("abc123xyz")
    output("1337h@xor!")
