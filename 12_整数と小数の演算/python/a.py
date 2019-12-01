#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    import math

    principal = input('Enter the principal: ')
    principal = int(principal)

    rate_of_interest = input('Enter the rate of interest: ')
    rate_of_interest = float(rate_of_interest)

    years = input('Enter the number of years: ')
    years = int(years)

    amount = principal * (1 + ((rate_of_interest / 100.0) * years))
    amount = math.floor(amount * 100.0 + 0.5)
    amount = amount / 100.0
    print(
        f"After {years} years at {rate_of_interest}%, the investment will be worth ${amount}.")
