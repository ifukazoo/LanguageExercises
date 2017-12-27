#!/usr/bin/env python
# coding: -utf8

import unittest
import anagram as a


class TestCap(unittest.TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_is_anagram(self):
        self.assertTrue(a.is_anagram("note", "tone"))
        self.assertTrue(a.is_anagram("cinerama", "american"))
        self.assertFalse(a.is_anagram("note", "TONE"))
        self.assertFalse(a.is_anagram("note", "tonee"))
        self.assertTrue(a.is_anagram("", ""))
        self.assertTrue(a.is_anagram("n", "n"))


if __name__ == '__main__':
    unittest.main()
