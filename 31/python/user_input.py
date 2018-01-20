#!/usr/bin/env python
# coding: -utf8

import sys


# readUserInput プロンプトを出してユーザー入力を取得する.
# EOFが入力された場合はプログラム終了する
def read_user_input(prompter):
    try:
        return input(prompter)
    except EOFError:
        sys.exit(1)


# readUserInputWithValidator プロンプトを出してユーザー入力を取得して,
# 希望の型に変換する.希望に沿わない入力だった場合は再度入力をうながす.
def read_user_input_with_validator(prompter, validator, invalidMsg):

    while True:
        user_input = read_user_input(prompter)
        try:
            return validator(user_input)
        except ValueError:
            print(invalidMsg)
            continue
