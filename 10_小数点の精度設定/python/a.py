#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    import functools

    REPEAT_COUNT = 3
    TAX_RATE = 5.5

    items = []
    for i in range(0, REPEAT_COUNT, 1):
        price = input(f"Enter the price of item {i+1}: ")
        price = int(price)

        quantity = input(f"Enter the quantity of item {i+1}: ")
        quantity = int(quantity)
        items.append((price, quantity))

    # タプルは[0],[1],...でアクセスできる
    subtotal = functools.reduce(
        lambda sum, item: sum + item[0] * item[1], items, 0)
    tax = subtotal * TAX_RATE / 100.0
    total = subtotal + tax

    print("Subtotal: $%.2f" % subtotal)
    print("Tax: $%.2f" % tax)
    print("Total: $%.2f" % total)
