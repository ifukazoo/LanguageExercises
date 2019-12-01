#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    import math

    principal_amount = input('What is the principal amount? ')
    principal_amount = int(principal_amount)

    rate = input('What is the rate? ')
    rate = float(rate)

    number_of_years = input('What is the number of years? ')
    number_of_years = int(number_of_years)

    number_of_years_per_year = input(
        'What is the number of times the interest is compounded per year? ')
    number_of_years_per_year = int(number_of_years_per_year)

    percent = rate / 100.0
    amount = principal_amount * \
        (1 + (percent / number_of_years_per_year)
         ) ** (number_of_years * number_of_years_per_year)

    amount = math.ceil(amount * 100) / 100

ceilでなくfloorを間違って使っているところがある. + 0.5 and floor => 四捨五入

    print(f"${principal_amount} invested at {rate}% for {number_of_years} years compounded {number_of_years_per_year} times per year is ${amount}.")
