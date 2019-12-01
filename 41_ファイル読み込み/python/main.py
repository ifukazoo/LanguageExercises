#!/usr/bin/env python
# coding: -utf8

import sys


def print_result(path, names):
    with open(path, 'wt') as f:
        f.write(f"Total of {len(names)} names" + "\n")
        f.write("-----------------\n")
        for name in names:
            f.write(name)


if __name__ == '__main__':

    names = []
    for line in sys.stdin:
        names.append(line)

    names.sort()
    print_result("result", names)
