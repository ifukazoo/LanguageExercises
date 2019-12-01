#!/usr/bin/env python
# coding: -utf8

import unittest
import validator as v


class TestCap(unittest.TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_validate_name(self):
        self.assertEqual(v.validate_name(""), False)
        self.assertEqual(v.validate_name("a"), False)
        self.assertEqual(v.validate_name("aa"), True)

    def test_validate_employee_id(self):
        self.assertEqual(v.validate_empoyee_id("AA-1234"), True)
        self.assertEqual(v.validate_empoyee_id("zz-0000"), True)

        self.assertEqual(v.validate_empoyee_id(" AA-1234"), False)
        self.assertEqual(v.validate_empoyee_id(""), False)
        self.assertEqual(v.validate_empoyee_id("AA-1234 "), False)
        self.assertEqual(v.validate_empoyee_id("AA-1234\n"), False)

        self.assertEqual(v.validate_empoyee_id("12-1234"), False)
        self.assertEqual(v.validate_empoyee_id("-1234"), False)
        self.assertEqual(v.validate_empoyee_id("A-1234"), False)
        self.assertEqual(v.validate_empoyee_id("AAA-1234"), False)
        self.assertEqual(v.validate_empoyee_id("A1-1234"), False)

        self.assertEqual(v.validate_empoyee_id("AA 1234"), False)
        self.assertEqual(v.validate_empoyee_id("AA1234"), False)

        self.assertEqual(v.validate_empoyee_id("AA-aaaa"), False)
        self.assertEqual(v.validate_empoyee_id("AA-"), False)
        self.assertEqual(v.validate_empoyee_id("AA-234"), False)
        self.assertEqual(v.validate_empoyee_id("AA-12345"), False)
        self.assertEqual(v.validate_empoyee_id("AA-A234"), False)

    def test_validate_zipcode(self):
        self.assertEqual(v.validate_zipcode("0"), True)
        self.assertEqual(v.validate_zipcode("1"), True)
        self.assertEqual(v.validate_zipcode("01"), True)
        self.assertEqual(v.validate_zipcode(""), False)
        self.assertEqual(v.validate_zipcode("a"), False)
        self.assertEqual(v.validate_zipcode("g"), False)


if __name__ == '__main__':
    unittest.main()
