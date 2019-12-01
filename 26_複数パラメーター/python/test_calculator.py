#!/usr/bin/env python
# coding: -utf8

import unittest
import calculator as c


class TestCap(unittest.TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_calculate_months_until_paid_off(self):
        self.assertEqual(c.calculate_months_until_paid_off(5000, 12, 100), 70)


if __name__ == '__main__':
    unittest.main()
