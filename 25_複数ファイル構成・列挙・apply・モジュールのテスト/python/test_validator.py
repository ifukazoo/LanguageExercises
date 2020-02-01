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
        self.assertEqual(p.password_validator(""),         p.Strength.VERY_WEAK)
        self.assertEqual(p.password_validator("1234567"),  p.Strength.VERY_WEAK)
        self.assertEqual(p.password_validator("aaaaaaa"),  p.Strength.WEAK)
        self.assertEqual(p.password_validator("aaaaaa@"),  p.Strength.NORMAL)
        self.assertEqual(p.password_validator("123456@"),  p.Strength.NORMAL)

        self.assertEqual(p.password_validator("aaaaaaaa"), p.Strength.NORMAL)
        self.assertEqual(p.password_validator("12345678"), p.Strength.NORMAL)
        self.assertEqual(p.password_validator("########"), p.Strength.NORMAL)
        self.assertEqual(p.password_validator("aaaaaaa8"), p.Strength.STRONG)
        self.assertEqual(p.password_validator("1234567a"), p.Strength.STRONG)
        self.assertEqual(p.password_validator("aaaaaa#8"), p.Strength.VERY_STRONG)
        self.assertEqual(p.password_validator("123456#a"), p.Strength.VERY_STRONG)


if __name__ == '__main__':
    unittest.main()
