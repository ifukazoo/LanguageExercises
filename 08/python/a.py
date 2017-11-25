#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    NUM_PIECES_PER_PIZZA = 8

    num_people = input("How many people? ")
    num_pizzas = input("How many pizzas do you have? ")
    print(f"{num_people} people with {num_pizzas} of pizza.")

    num_people = int(num_people)
    num_pizzas = int(num_pizzas)

    num_pieces = NUM_PIECES_PER_PIZZA * num_pizzas
    quotient, remainder = divmod(num_pieces, num_people)

    print(f"Each person gets {quotient} pieces of pizza.")
    print(f"There are {remainder} leftover pieces.")
