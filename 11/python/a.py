#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    import math

    euros = input("How many euros are you exchanging? ")
    euros = int(euros)

    rate = input("What is the exchange rate? ")
    rate = float(rate)

    us_dollars = float(euros) * rate / 100.0
    us_dollars = math.floor((us_dollars * 100.0) + 0.5)/ 100.0

    print(f"{euros} euros at an exchante rate of {rate} is {us_dollars} U.S. dollars.")
