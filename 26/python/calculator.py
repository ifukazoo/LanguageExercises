#!/usr/bin/env python
# coding: -utf8
#


def calculate_months_until_paid_off(balance, arp, payment):
    import math
    # 公式
    # n = -(1/30) x log(1 + (b/p) x (1 - (1+i)^30)) / log(1+i)
    #
    # n is the number of months.
    # i is the daily rate (APR divided by 365).
    # b is the balance.
    # p is the monthly payment.

    i = arp / 100.0 / 365
    b = balance
    p = payment

    n = -(1.0 / 30.0) * math.log(1 + (b / p) *
                                 (1 - math.pow(1 + i, 30))) / math.log(1 + i)
    return int(math.ceil(n))
