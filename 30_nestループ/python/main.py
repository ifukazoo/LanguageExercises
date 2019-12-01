#!/usr/bin/env python
# coding: -utf8


def table_printer(begin, do_work, end):
    begin()
    for col in range(13):
        do_work(col)
    end()


def print_header():
    table_printer(
        lambda: print("|    ", end=""),
        lambda col: print("|%4d" % col, end=""),
        lambda: print("|\n", end=""),
    )


def print_horizontal_line():
    table_printer(
        lambda: print("+----", end=""),
        lambda _: print("+----", end=""),
        lambda: print("+\n", end=""),
    )


def print_row(row):
    table_printer(
        lambda: print("|%4d" % row, end=""),
        lambda col: print("|%4d" % (row * col), end=""),
        lambda: print("|\n", end=""),
    )


if __name__ == '__main__':
    print_horizontal_line()
    print_header()
    for i in range(13):
        print_horizontal_line()
        print_row(i)
    print_horizontal_line()
