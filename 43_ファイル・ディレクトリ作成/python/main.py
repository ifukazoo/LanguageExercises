#!/usr/bin/env python
# coding: -utf8

import user_input as ui
import os
import string


def every_input_ok(s):
    return s


def validate_not_empty(s):
    stripped = s.strip()
    if len(stripped) == 0:
        raise ValueError

    return stripped


def validate_yes_no(s):
    stripped = s.strip()
    if len(stripped) == 0:
        raise ValueError

    return stripped[0].lower() == 'y'


def create_index_html(path, title, author_name):
    templ = '''
<!DOCTYPE html>
<html>
    <head>
        <title>${Title}</title>
        <meta name="author" content="${Author}">
    </head>
</html>
'''
    t = string.Template(templ)
    html = t.substitute(Title=title, Author=author_name)
    with open(path, 'wt') as f:
        f.write(html)


def make_directories(path):
    if not os.path.exists(path):
        os.makedirs(path)


if __name__ == '__main__':

    WRONG_INPUT_MSG = "Sorry. That's not a valid input."

    site_name = ui.read_user_input_with_validator(
        "Site name: ",  validate_not_empty, WRONG_INPUT_MSG)

    author_name = ui.read_user_input_with_validator(
        "Author: ",  validate_not_empty, WRONG_INPUT_MSG)

    has_js = ui.read_user_input_with_validator(
        "Do you want a folder fo JavaScript? ",  validate_yes_no, WRONG_INPUT_MSG)

    has_css = ui.read_user_input_with_validator(
        "Do you want a folder fo CSS? ",  validate_yes_no, WRONG_INPUT_MSG)

    site_dir_path = "./" + site_name
    make_directories(site_dir_path)
    print(f"Created {site_dir_path}")

    index_path = site_dir_path + "/index.html"
    create_index_html(index_path, site_name, author_name)
    print(f"Created {index_path}")

    if has_js:
        site_js_dir_path = site_dir_path + "/js"
        make_directories(site_js_dir_path)
        print(f"Created {site_js_dir_path}")

    if has_css:
        site_css_dir_path = site_dir_path + "/css"
        make_directories(site_css_dir_path)
        print(f"Created {site_css_dir_path}")
