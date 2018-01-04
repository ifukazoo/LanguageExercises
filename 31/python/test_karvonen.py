#!/usr/bin/env python
# coding: -utf8

import unittest
import karvonen as k


class TestCap(unittest.TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_calc_heart_rate(self):
        self.assertEqual(k.calc_heart_rate(22, 65, 55), 138)
        self.assertEqual(k.calc_heart_rate(22, 65, 60), 145)
        self.assertEqual(k.calc_heart_rate(22, 65, 65), 151)
        self.assertEqual(k.calc_heart_rate(22, 65, 70), 158)
        self.assertEqual(k.calc_heart_rate(22, 65, 75), 165)
        self.assertEqual(k.calc_heart_rate(22, 65, 80), 171)
        self.assertEqual(k.calc_heart_rate(22, 65, 85), 178)
        self.assertEqual(k.calc_heart_rate(22, 65, 90), 185)
        self.assertEqual(k.calc_heart_rate(22, 65, 95), 191)


if __name__ == '__main__':
    unittest.main()
