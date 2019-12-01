#!/usr/bin/env python
# coding: -utf8


def is_anagram(a, b):
    if len(a) != len(b):
        return False
    for ch in b:
        if not ch in a:
            return False
    return True
