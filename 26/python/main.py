#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    import calculator as c
    import sys

    user_input = input("What is your balance? ")
    balance = int(user_input)

    user_input = input("What is the ARP on the card (as a percent)? ")
    arp = int(user_input)

    user_input = input("What is the monthly payment you can make? ")
    payment = int(user_input)

    try:
        months = c.calculate_months_until_paid_off(balance, arp, payment)
    except ValueError:
        print("You can't pay off this card.")
        sys.exit(1)

    print(f"It will take you {months} months to pay off this card.")
