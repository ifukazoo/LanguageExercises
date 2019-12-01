#!/usr/bin/env python
# coding: -utf8

import user_input as ui
import sys
import json


def validate_not_empty(s):
    stripped = s.strip()
    if len(stripped) == 0:
        raise ValueError

    return stripped


def find_first(iterable, pred):
    default = False
    return next(filter(pred, iterable), default)


def disp(product):
    print("Name: %s" % product['name'])
    print("Price: $%.2f" % product['price'])
    print("Quantity on hand: %d" % product['quantity'])


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <json file>", file=sys.stderr)
        sys.exit(1)

    products = None
    with open(sys.argv[1], 'rt') as f:
        loaded = json.load(f)
        products = loaded["products"]

    WRONG_INPUT_MSG = "Sorry, that product was not found in our inventory."

    while True:
        name = ui.read_user_input_with_validator(
            "What is the procuct name? ", validate_not_empty, WRONG_INPUT_MSG)

        def pred(procuct): return procuct['name'] == name

        found = find_first(products, pred)

        if found:
            disp(found)
            break

        print(WRONG_INPUT_MSG)
