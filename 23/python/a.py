#!/usr/bin/env python
# coding: -utf8


class DecisionNode():
    def __init__(self, message):
        self.message = message
        self.case_yes = None
        self.case_no = None

    def has_next(self):
        return not (self.case_yes == None or self.case_no == None)

    def do_work(self):
        if self.has_next():
            answer = input(self.message)
            if answer.upper() == 'Y':
                self.case_yes.do_work()
            else:
                self.case_no.do_work()
        else:
            print(self.message)

if __name__ == '__main__':
    q1 = DecisionNode("Is the car silent when you turn the key? ")
    q2 = DecisionNode("Are the battery terminals corroded? ")
    q3 = DecisionNode("Does the car make a clicking noise? ")
    q4 = DecisionNode("Clean terminals and try starting again.")
    q5 = DecisionNode("Replace cables and try again.")
    q6 = DecisionNode("Replace the battery.")
    q7 = DecisionNode("Does the car crank up but fail to start? ")
    q8 = DecisionNode("Check spark plug connections.")
    q9 = DecisionNode("Does the engine start and then die? ")
    q10 = DecisionNode("Does your car have fuel injection? ")
    q11 = DecisionNode("Check to ensure the choke is opening and closing.")
    q12 = DecisionNode("Get it in for service.")

    q1.case_yes = q2
    q1.case_no = q3

    q2.case_yes = q4
    q2.case_no = q5

    q3.case_yes = q6
    q3.case_no = q7

    q7.case_yes = q8
    q7.case_no = q9

    q9.case_yes = q10
    q9.case_no = q12

    q10.case_no = q11
    q10.case_yes = q12

    q1.do_work()
