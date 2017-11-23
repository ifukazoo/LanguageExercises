#!/usr/bin/env python
# coding: -utf8
import math

PAINTABLE_PER_GALLON = 350.0

length_room = input("What is the length of the room in feet? ")
length_room = int(length_room)

width_room = input("What is the width of the room in feet? ")
width_room = int(width_room)

square_feet = length_room * width_room
galon = square_feet / PAINTABLE_PER_GALLON
num_gallon = int(math.ceil(galon))

print(
    f"You will need to purchase {num_gallon} gallons of paint to cover {square_feet} square feet.")
