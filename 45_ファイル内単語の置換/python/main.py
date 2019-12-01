#!/usr/bin/env python
# coding: -utf8

import user_input as ui
import sys


def validate_not_empty(s):
    stripped = s.strip()
    if len(stripped) == 0:
        raise ValueError

    return stripped


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <input file>", file=sys.stderr)
        sys.exit(1)

    WRONG_INPUT_MSG = "Sorry. That's not a valid input."

    name = ui.read_user_input_with_validator(
        "What is the output file name? ", validate_not_empty, WRONG_INPUT_MSG)

    with open(sys.argv[1], 'rt') as ifs, open(name, 'wt') as ofs:
        line = ifs.readline()
        newline = line.replace("utilize", "use")
        ofs.write(newline)
