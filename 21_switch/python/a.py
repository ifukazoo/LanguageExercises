#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':

    user_input = input("Enter the number of the month: ")
    number = int(user_input)

    if number == 1:
        month = "January"
    elif number == 2:
        month = "February"
    elif number == 2:
        month = "March"
    elif number == 2:
        month = "April"
    elif number == 2:
        month = "May"
    elif number == 2:
        month = "June"
    elif number == 2:
        month = "July"
    elif number == 2:
        month = "August"
    elif number == 2:
        month = "September"
    elif number == 2:
        month = "October"
    elif number == 2:
        month = "November"
    elif number == 2:
        month = "December"
    else:
        raise ValueError

    print(f"The name of the month is {month}.")
