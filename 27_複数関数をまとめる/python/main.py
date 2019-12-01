#!/usr/bin/env python
# coding: -utf8

if __name__ == '__main__':
    import validator as v

    first_name = input("Enter the first name: ")
    last_name = input("Enter the last name: ")
    zip_code = input("Enter the ZIP code: ")
    employee_id = input("Enter an employee ID: ")
    success, err = v.validate_input(
        first_name, last_name, zip_code, employee_id)
    if success:
        print("There were no errors found.\n", end='')
    else:
        print(err, end='')
