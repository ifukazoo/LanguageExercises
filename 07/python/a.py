#!/usr/bin/env python
# coding: -utf8
import math

FEET_TO_METER_COFF = 0.09290304

length_of_feet = input("What is the length of the room in feet? ")
width_of_feet = input("What is the width of the room in feet? ")
print(
    f"You entered dimensions of {length_of_feet} feet by {width_of_feet} feet.")

square_feet = int(length_of_feet) * int(width_of_feet)

# 小数点4桁目を四捨五入
square_meters = square_feet * (FEET_TO_METER_COFF * 100000000)
square_meters = square_meters / 100000.0
square_meters = math.floor(square_meters + 0.5)
square_meters = square_meters / 1000.0

print("The area is ")
print(f"{square_feet} square feet")
print(f"{square_meters} square meters")
