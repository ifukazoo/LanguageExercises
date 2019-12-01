#!/usr/bin/env python
# coding: -utf8
#
import user_input as ui
import random

INVALID_MSG = "Sorry. That's not a valid input."


def start_game():
    print("Let's play Guess the Number.")

    level = ui.read_user_input_with_validator(
        "Pick a difficulty level (1, 2, or 3): ", validate_level,  INVALID_MSG)

    count = start_guess(level)

    print(f"You got it in {count} guess!")


def start_guess(level):
    goal = generate_goal_number(level)
    print("I have my number. ", end="")

    guess = ui.read_user_input_with_validator(
        "What's your guess? ", validate_number, INVALID_MSG)
    try_count = 1
    while guess != goal:
        if guess < goal:
            print("Too low. ", end="")
        else:
            print("Too high. ", end="")

        guess = ui.read_user_input_with_validator(
            "Guess again: ", validate_number, INVALID_MSG)

        try_count += 1

    return try_count


def validate_level(s):
    level = int(s)
    if not (level == 1 or level == 2 or level == 3):
        raise ValueError
    return level


def generate_goal_number(level):
    max = 10 ** level
    return random.choice(range(1, max + 1))


def validate_number(s):
    return int(s)
