#!/usr/bin/env python
# coding: -utf8

import user_input as ui
import random


def validate_number(s):
    return int(s)


def generate_password(num_special, num_number, num_min):
    assert(num_special + num_number <= num_min)

    alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    numbers = "0123456789"
    special_chars = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~}"

    # パスワードに使う文字を集める
    characters_selected = []
    for i in range(num_special):
        characters_selected.append(random.choice(special_chars))

    for i in range(num_number):
        characters_selected.append(random.choice(numbers))

    for i in range(num_min - num_special - num_number):
        characters_selected.append(random.choice(alphabets))

    random.shuffle(characters_selected)
    return ''.join(characters_selected)


if __name__ == '__main__':

    invalid_msg = "Sorry. That's not a valid input."
    num_min = ui.read_user_input_with_validator(
        "What's the minimum length? ", validate_number, invalid_msg)

    num_special = ui.read_user_input_with_validator(
        "How many special characters? ", validate_number, invalid_msg)

    num_number = ui.read_user_input_with_validator(
        "How many numbers? ", validate_number, invalid_msg)

    print(generate_password(num_special, num_number, num_min))
