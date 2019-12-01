#!/usr/bin/env python
# coding: -utf8

import sys
import functools as ft


def get_max_field_length(records):
    # すべてのレコードをフィールドの長さを格納したレコードに変換する
    # [["abc","a"],["ab","ab"]] => [[3,1],[2,2]]
    lengths_of_record = map(lambda record: map(
        lambda field: len(field), record), records)

    # 大きい値に集約する
    # [3,1],[2,2] => [3,2]
    def max_of(left, right):
        # [3,1],[2,2] => [(3,2), (1,2)]
        tuple = zip(left, right)
        return map(lambda tpl: max(tpl), tuple)

    # 最大長を集計する
    # [[3,1],[2,2],[4,0]] => [4,2]
    max_field_length = ft.reduce(
        lambda acc, record: max_of(acc, record),  lengths_of_record)

    return max_field_length


def print_line(left, mid, right, left_w, mid_w, right_w):
    format = '%-{}s%-{}s%-{}s'.format(left_w, mid_w, right_w)
    print(format % (left, mid, right))


def print_hr(left_w, mid_w, right_w):
    width = left_w + mid_w + right_w
    for _ in range(width):
        print('-', end="")
    print('')


def print_result(records):
    # フィールドの最大長を取得する
    max_field_length = get_max_field_length(records)
    last_w, first_w, salary_w = map(lambda w: w + 1, max_field_length)

    # タイトル
    print_line("Last", "First", "Salary", last_w, first_w, salary_w)

    # 水平線
    print_hr(last_w, first_w, salary_w)

    # 内容
    for record in records:
        print_line(record[0], record[1], record[2],  last_w, first_w, salary_w)


def read_csv_lines(f):
    records = []
    for line in f:
        records.append(line.rstrip().split(','))
    return records


if __name__ == '__main__':

    records = None
    if len(sys.argv) == 1:
        records = read_csv_lines(sys.stdin)
    else:
        with open(sys.argv[1], 'rt') as f:
            records = read_csv_lines(f)

    print_result(records)
