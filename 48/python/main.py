#!/usr/bin/env python
# coding: -utf8

import json
import urllib.request as ur

import user_input as ui


def validate_not_empty(s):
    stripped = s.strip()
    if len(stripped) == 0:
        raise ValueError

    return stripped


if __name__ == '__main__':

    WRONG_INPUT_MSG = "Sorry. That's not a valid input."

    apiid = ui.read_user_input_with_validator(
        "What is your openweather api appid? ", validate_not_empty, WRONG_INPUT_MSG)
    city = ui.read_user_input_with_validator(
        "Where are you? ", validate_not_empty, WRONG_INPUT_MSG)

    with ur.urlopen(f"http://api.openweathermap.org/data/2.5/weather?q={city}&APPID={apiid}&units=metric") as stream:
        res = json.loads(stream.read())
        if res['cod'] == 200:
            weather = res['weather'][0]
            desc = weather['main']
            print(f"{city} weather: {desc}")

            main = res['main']
            temp = main['temp']
            print(f"{temp} degrees Celsius")
