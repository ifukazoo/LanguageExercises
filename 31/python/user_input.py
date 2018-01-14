#!/usr/bin/env python
# coding: -utf8


def read_user_input(prompter, invalid_msg):
    while True:
        try:
            user_input = input(prompter)
            return int(user_input), False
        except EOFError:
            return 0, True
        except ValueError:
            print(invalid_msg)
            continue
