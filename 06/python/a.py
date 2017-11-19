#!/usr/bin/env python
# coding: -utf8
import sys
import datetime

age = input("What is your current age? ")
retire_age = input("At what age would you like to retire? ")
age = int(age)
retire_age = int(retire_age)
this_year = datetime.date.today().year
print("You have %d years left until you can retire." % (retire_age - age))
print("It's %d, so you can retire in %d." %
      (this_year, this_year + (retire_age - age)))
