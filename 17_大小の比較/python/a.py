#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    user_input = input("What is your weight? ")
    weight = float(user_input)

    user_input = input("Which is your gender 1:male 2:femail ? ")
    gender = int(user_input)

    user_input = input("What is the amount of alcohol by volume? ")
    amount_of_alcohol = float(user_input)

    user_input = input("How long has it passed since you drunk? ")
    num_hours = int(user_input)

    A = amount_of_alcohol
    W = weight
    r = 0.73 if gender == 1 else 0.66
    H = float(num_hours)
    bac = (A * 5.14 / W * r) - 0.015 * H
    # A is total alcohol consumed, in ounces(oz).
    # W is body weight in pounds.
    # r is the alcohol distribution ratio:
    # 0.73 for men
    # 0.66 for women
    # H is number of hours since the last drink.

    print("Your BAC is %.2f" % bac)
    print(f'It is {"not " if bac > 0.08 else ""}legal for you to drive.')
