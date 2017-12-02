#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    import math
    TAX_WI = 5.5

    user_input = input("What is the order amount? ")
    amount = float(user_input)

    user_input = input("What is the state? ")
    state = user_input

    tax = 0.0
    if (state == "WI"):
        tax = amount * (TAX_WI / 100.0)
        print("The subtotal is $%.2f." % amount)
        print("The tax is $%.2f." % tax)

    total_amount = math.floor((amount + tax) * 100.0) / 100.0
    print("The total is $%.2f." % total_amount)
