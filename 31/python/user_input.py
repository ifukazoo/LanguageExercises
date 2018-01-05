#!/usr/bin/env python
# coding: -utf8

import sys

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

