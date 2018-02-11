#!/usr/bin/env python
# coding: -utf8


class Employee():
    def __init__(self, first_name, last_name, position, separation_date):
        self.first_name = first_name
        self.last_name = last_name
        self.position = position
        self.separation_date = separation_date

    def __str__(self):
        return f"{self.first_name} {self.last_name} {self.position} {self.separation_date}"


def print_cel(s):
    print("%-23s" % s, end="")


def print_row(left, middle, right):
    print_cel(left)
    print_cel("|" + middle)
    print_cel("|" + right)
    print("")


if __name__ == '__main__':

    employees = [
        Employee("John", "Johnson", "Manager", "2016-12-31"),
        Employee("Tou", "Xiong", "Software Engineer", "2016-10-05"),
        Employee("Michaela", "Michaelson", "District Manager", "2015-12-19"),
        Employee("Jake", "Jacobson", "Programmer", ""),
        Employee("Jacquelyn", "Jackson", "DBA", ""),
        Employee("Sally", "Weber", "Web Developer", "2015-12-18")
    ]
    employees.sort(key=lambda e: e.last_name)

    print_row("Name", " Position", " Separation Date")
    print_row("-----------------------",
              "----------------------", "----------------------")
    for employee in employees:
        print_row(employee.first_name + " " + employee.last_name,
                  " " + employee.position, " " + employee.separation_date)
