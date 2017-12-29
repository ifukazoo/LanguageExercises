#!/usr/bin/env python
# coding: -utf8
#

import re


def validate_input(first_name, last_name, zip_code, employee_id):
    err_msg = ""
    success, err = validate_name_and_make_error(first_name, "first")
    if not success:
        err_msg += err

    success, err = validate_name_and_make_error(last_name, "last")
    if not success:
        err_msg += err

    if not validate_zipcode(zip_code):
        err_msg += "The ZIP code must be numeric.\n"

    if not validate_empoyee_id(employee_id):
        err_msg += ("%s is not a valid ID.\n" % employee_id)

    return len(err_msg) == 0, err_msg


def validate_name_and_make_error(user_input, first_or_last):
    if len(user_input) == 0:
        return False, ("The %s name must be filled in.\n" % first_or_last)

    if not validate_name(user_input):
        return False, ("\"%s\" is not a valid %s name. It is too short.\n" % (user_input, first_or_last))

    return True, ""


def validate_name(user_input):
    return len(user_input) >= 2


def validate_empoyee_id(user_input):
    # pythonに\zは存在しない
    pattern = re.compile("\A[a-zA-Z]{2}-\d{4}\Z")
    return pattern.match(user_input) != None


def validate_zipcode(user_input):
    if len(user_input) == 0:
        return False
    return all_of(user_input, is_digit)


def all_of(a, f):
    for c in a:
        if not f(c):
            return False
    return True


def is_digit(s):
    return s.isdigit()
