#!/usr/bin/env python
# coding: -utf8

import unittest
import validator as p


class TestCap(unittest.TestCase):
    def setUp(self):
        pass


def tearDown(self):
    pass


def test_password_validator(self):
    self.assertEqual(p.password_validator(""),         Strength.VERY_WEAK)
    self.assertEqual(p.password_validator("1234567"),  Strength.VERY_WEAK)
    self.assertEqual(p.password_validator("aaaaaaa"),  Strength.WEAK)
    self.assertEqual(p.password_validator("aaaaaa@"),  Strength.NORMAL)
    self.assertEqual(p.password_validator("123456@"),  Strength.NORMAL)

    self.assertEqual(p.password_validator("aaaaaaaa"), Strength.NORMAL)
    self.assertEqual(p.password_validator("12345678"), Strength.NORMAL)
    self.assertEqual(p.password_validator("########"), Strength.NORMAL)
    self.assertEqual(p.password_validator("aaaaaaa8"), Strength.STRONG)
    self.assertEqual(p.password_validator("1234567a"), Strength.STRONG)
    self.assertEqual(p.password_validator("aaaaaa#8"), Strength.VERY_STRONG)
    self.assertEqual(p.password_validator("123456#a"), Strength.VERY_STRONG)


if __name__ == '__main__':
    unittest.main()
