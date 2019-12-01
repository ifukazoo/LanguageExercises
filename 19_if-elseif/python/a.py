#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':

    height = input("Enter your height(inch): ")
    height = float(height)

    weight = input("Enter your weight(pound): ")
    weight = float(weight)

    bmi = (weight / (height * height)) * 703
    bmi = ((bmi * 10) + 0.5) / 10.0

    print("Yor BMI is %.1f." % bmi)
    if bmi < 18.5:
        print("Yor are underweight. You should see your doctor.")
    elif 18.5 <= bmi <= 25:
        print("Yor are whthin the ideal weight range.")
    else:
        print("Yor are overweight. You should see your doctor.")
