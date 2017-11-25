#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    theQuote = r"These aren't the droids you're looking for."
    print("What is the quoter? " + theQuote)
    userinput = input('Who said it? ')
    print(userinput + " says, " + '"' + theQuote + '"')
