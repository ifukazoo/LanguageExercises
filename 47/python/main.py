#!/usr/bin/env python
# coding: -utf8

import urllib.request as ur
import functools as ft
import json


def max_name_len(astros):
    def f(acc, astro):
        name = astro["name"]
        if acc > len(name):
            return acc
        else:
            return len(name)
    return ft.reduce(f, astros, 0)


def disp_line(left, left_w, right,  right_w):
    lfmt = '%-{}s'.format(left_w + 1)
    rfmt = '%-{}s'.format(right_w)
    print((lfmt + "|" + rfmt) % (left, right))


def disp_separator(leftlen, rightlen):
    lsep = ""
    for i in range(0, leftlen):
        lsep += "-"

    rsep = ""
    for i in range(0, rightlen):
        rsep += "-"

    disp_line(lsep, leftlen, rsep, rightlen)


def disp_astros(astros):
    name_field_len = max_name_len(astros)
    disp_line("Name", name_field_len, " Craft", 6)
    disp_separator(name_field_len, 6)
    for a in astros:
        disp_line(a["name"], name_field_len, " " + a["craft"], 6)


if __name__ == '__main__':
    with ur.urlopen("http://api.open-notify.org/astros.json") as stream:
        res = json.loads(stream.read())

        if res['message'] == 'success':
            disp_astros(res['people'])
