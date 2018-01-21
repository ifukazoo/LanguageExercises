#!/usr/bin/env python
# coding: -utf8

import user_input as ui
import random



if __name__ == '__main__':
    contestants = []

    while True:
        name = ui.read_user_input("Enter a name: ")
        if len(name) == 0:
            break
        contestants.append(name)

    if len(contestants) > 0:
        winner = random.choice(contestants)
        print(f"The winner is ... {winner}.")
