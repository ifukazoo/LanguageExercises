#!/usr/bin/env python
# coding: -utf8

import unittest
import filter


class TestCap(unittest.TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_filter_even_numbers(self):
        self.assertListEqual(filter.filter_even_numbers([]), [])
        self.assertListEqual(filter.filter_even_numbers([1]), [])
        self.assertListEqual(filter.filter_even_numbers([1, 3]), [])
        self.assertListEqual(filter.filter_even_numbers([0]), [0])
        self.assertListEqual(filter.filter_even_numbers([0, 1, 2]), [0, 2])


if __name__ == '__main__':
    unittest.main()
