#!/usr/bin/env python
# coding: -utf8

import sys
import functools


def disp_hist(freq):

    max_wordlen = functools.reduce(
        lambda m, kv: len(kv[0]) if m < len(kv[0]) else m, freq, 0)

    fmt = "%%-0%ds" % (max_wordlen + 2)
    for kv in freq:
        title = kv[0] + ": "
        print(fmt % title, end="")
        star = ""
        for n in range(0, kv[1]):
            print("*", end="")
        print("")


def count_word_freq(path):
    freq = {}
    with open(path, 'rt') as ifs:
        for line in ifs:
            words = line.split(' ')
            words = map(lambda w: w.strip(), words)
            words = filter(lambda x: len(x) > 0 and x.isalpha(), words)
            for w in words:
                if w in freq:
                    freq[w] = freq[w] + 1
                else:
                    freq[w] = 1
    return freq


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <input file path>", file=sys.stderr)
        sys.exit(1)

    freq_dic = count_word_freq(sys.argv[1])
    freq = []
    for kv in freq_dic.items():
        freq.append(kv)
    freq.sort(key=lambda v: v[1], reverse=True)

    disp_hist(freq)
