#include <cstdio>
#include <climits>

#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <string>
#include <iostream>
#include <numeric>
#include "gtest/gtest.h"

namespace {
#include "p.cc"

TEST(Test, string_to_integer_a) {
  std::pair<bool, long> result = string_to_integer<long>("a");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_integer_a0) {
  std::pair<bool, long> result = string_to_integer<long>("0a");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_integer_empty) {
  std::pair<bool, long> result = string_to_integer<long>("");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_integer_toolarge) {
  std::pair<bool, long> result = string_to_integer<long>("9223372036854775808");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_integer_toosmall) {
  std::pair<bool, long> result = string_to_integer<long>("-9223372036854775809");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_char_toolarge) {
  std::pair<bool, char> result = string_to_integer<char>("128");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_char_toosmall) {
  std::pair<bool, char> result = string_to_integer<char>("-129");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_int_toolarge) {
  std::pair<bool, int> result = string_to_integer<int>("2147483648");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_int_toosmall) {
  std::pair<bool, int> result = string_to_integer<int>("-2147483649");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_integer_0) {
  std::pair<bool, long> result = string_to_integer<long>("0");
  EXPECT_TRUE(result.first);
  EXPECT_EQ(0, result.second);
}
TEST(Test, string_to_integer_1) {
  std::pair<bool, long> result = string_to_integer<long>("1");
  EXPECT_TRUE(result.first);
  EXPECT_EQ(1, result.second);
}
TEST(Test, string_to_integer_plus1) {
  std::pair<bool, long> result = string_to_integer<long>("+1");
  EXPECT_TRUE(result.first);
  EXPECT_EQ(1, result.second);
}
TEST(Test, string_to_integer_minus1) {
  std::pair<bool, long> result = string_to_integer<long>("-1");
  EXPECT_TRUE(result.first);
  EXPECT_EQ(-1, result.second);
}
TEST(Test, string_to_integer_max) {
  char buf[32];
  sprintf(buf, "%ld", LONG_MAX);
  std::string s(buf);
  std::cout << s << std::endl;
  std::pair<bool, long> result = string_to_integer<long>(s);
  EXPECT_TRUE(result.first);
  EXPECT_EQ(LONG_MAX, result.second);
}
TEST(Test, string_to_integer_min) {
  char buf[32];
  sprintf(buf, "%ld", LONG_MIN);
  std::string s(buf);
  std::cout << s << std::endl;
  std::pair<bool, long> result = string_to_integer<long>(s);
  EXPECT_TRUE(result.first);
  EXPECT_EQ(LONG_MIN, result.second);
}
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
