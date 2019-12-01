#!/usr/bin/env python
# coding: -utf8

import random
import user_input as ui

if __name__ == '__main__':
    answers = ["Yes", "No", "Maybe", "Ask again later"]
    ui.read_user_input("What's your question? ")
    answer = random.choice(answers)
    print(f"{answer}.")
