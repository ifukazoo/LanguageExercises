#!/usr/bin/env python
# coding: -utf8

import user_input as ui


def disp_employees(employees):
    print(f"There are {len(employees)} employees:")

    for employee in employees:
        print(employee)


if __name__ == '__main__':
    employees = ["Jhon Smith", "Jackie Jackson",
                 "Chris Jones", "Amanda Cullen", "Jeremy Goodwin"]
    disp_employees(employees)

    print()
    name = ui.read_user_input("Enter an employee name to remove: ")
    print()

    if name in employees:
        employees.remove(name)
        disp_employees(employees)
    else:
        print(f"Not found {name}.")
