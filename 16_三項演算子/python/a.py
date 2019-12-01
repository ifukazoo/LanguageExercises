#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    legal_driving_age = 16

    user = input("What is your age? ")
    age = int(user)
    print(
        f'You are {"not " if age < legal_driving_age else ""}old enough to legally drive.')
