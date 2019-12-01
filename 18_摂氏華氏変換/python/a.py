#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    print("Press C to convert from Fahrenheit to Celsius.")
    print("Press F to convert from Celsius to Fahrenheit.")
    choice = input("Your choice: ")
    choice = choice.upper()[0]

    if choice == "C":
        frm = "Fahrenheit"
        to = "Celsius"
    else:
        frm = "Celsius"
        to = "Fahrenheit"

    to_convert = input(f"Please enter the temperature in {frm}: ")
    source = float(to_convert)
    if to == "Celsius":
        dest = (source - 32.0) * 5.0 / 9.0
    else:
        dest = (source * 9.0 / 5.0) + 32.0
    print(f"The temperature in {to} is {dest}.")
