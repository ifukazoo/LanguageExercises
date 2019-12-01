#!/usr/bin/env python
# coding: -utf8

import user_input as ui
import guessgame as game


def user_want_to_continue():
    user_input = ui.read_user_input("Play again? ")
    return user_input.upper()[0] == 'Y'


if __name__ == '__main__':
    while True:
        game.start_game()

        if not user_want_to_continue():
            break

    print("Goodbye!")
