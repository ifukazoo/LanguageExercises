#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    password_data = {
        'figaro':   'abcd',
        'susanna':  '1234',
        'almaviva': 'ABCD',
        'rosina':   '5678',
    }

    input_username = input("What is the usernames? ")
    input_password = input("What is the password? ")

    if input_username not in password_data:
        print("I don't know you.")
    else:
        password = password_data[input_username]
        if input_password == password:
            print("Welcome!")
        else:
            print("I don't know you.")
