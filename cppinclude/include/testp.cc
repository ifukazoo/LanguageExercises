#include <cstdio>
#include "gtest/gtest.h"

#include <climits>
#include "functions.h"

TEST(Test, str_to_i_a) {
  std::pair<bool, long> result = str_to_i<long>("a");
  EXPECT_FALSE(result.first);
}
TEST(Test, str_to_i_a0) {
  std::pair<bool, long> result = str_to_i<long>("0a");
  EXPECT_FALSE(result.first);
}
TEST(Test, str_to_i_empty) {
  std::pair<bool, long> result = str_to_i<long>("");
  EXPECT_FALSE(result.first);
}
TEST(Test, str_to_i_toolarge) {
  std::pair<bool, long> result = str_to_i<long>("9223372036854775808");
  EXPECT_FALSE(result.first);
}
TEST(Test, str_to_i_toosmall) {
  std::pair<bool, long> result = str_to_i<long>("-9223372036854775809");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_char_toolarge) {
  std::pair<bool, char> result = str_to_i<char>("128");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_char_toosmall) {
  std::pair<bool, char> result = str_to_i<char>("-129");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_int_toolarge) {
  std::pair<bool, int> result = str_to_i<int>("2147483648");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_int_toosmall) {
  std::pair<bool, int> result = str_to_i<int>("-2147483649");
  EXPECT_FALSE(result.first);
}
TEST(Test, str_to_i_0) {
  std::pair<bool, long> result = str_to_i<long>("0");
  EXPECT_TRUE(result.first);
  EXPECT_EQ(0, result.second);
}
TEST(Test, str_to_i_1) {
  std::pair<bool, long> result = str_to_i<long>("1");
  EXPECT_TRUE(result.first);
  EXPECT_EQ(1, result.second);
}
TEST(Test, str_to_i_plus1) {
  std::pair<bool, long> result = str_to_i<long>("+1");
  EXPECT_TRUE(result.first);
  EXPECT_EQ(1, result.second);
}
TEST(Test, str_to_i_minus1) {
  std::pair<bool, long> result = str_to_i<long>("-1");
  EXPECT_TRUE(result.first);
  EXPECT_EQ(-1, result.second);
}
TEST(Test, str_to_i_max) {
  char buf[32];
  sprintf(buf, "%ld", LONG_MAX);
  std::string s(buf);
  std::cout << s << std::endl;
  std::pair<bool, long> result = str_to_i<long>(s);
  EXPECT_TRUE(result.first);
  EXPECT_EQ(LONG_MAX, result.second);
}
TEST(Test, str_to_i_min) {
  char buf[32];
  sprintf(buf, "%ld", LONG_MIN);
  std::string s(buf);
  std::cout << s << std::endl;
  std::pair<bool, long> result = str_to_i<long>(s);
  EXPECT_TRUE(result.first);
  EXPECT_EQ(LONG_MIN, result.second);
}

TEST(Test, str_to_f_0) {
  std::pair<bool, double> result = str_to_f<double>("0");
  EXPECT_TRUE(result.first);
  EXPECT_DOUBLE_EQ(0.0, result.second);
}
TEST(Test, str_to_f_point0) {
  std::pair<bool, double> result = str_to_f<double>(".0");
  EXPECT_TRUE(result.first);
  EXPECT_DOUBLE_EQ(0.0, result.second);
}
TEST(Test, str_to_f_0point0) {
  std::pair<bool, double> result = str_to_f<double>("0.0");
  EXPECT_TRUE(result.first);
  EXPECT_DOUBLE_EQ(0.0, result.second);
}
TEST(Test, str_to_f_1) {
  std::pair<bool, double> result = str_to_f<double>("1.0");
  EXPECT_TRUE(result.first);
  EXPECT_DOUBLE_EQ(1.0, result.second);
}
TEST(Test, str_to_f_plus1) {
  std::pair<bool, double> result = str_to_f<double>("+1.0");
  EXPECT_TRUE(result.first);
  EXPECT_DOUBLE_EQ(1.0, result.second);
}
TEST(Test, str_to_f_minus1) {
  std::pair<bool, double> result = str_to_f<double>("-1.1");
  EXPECT_TRUE(result.first);
  EXPECT_DOUBLE_EQ(-1.1, result.second);
}
TEST(Test, str_to_f_scientic) {
  std::pair<bool, double> result = str_to_f<double>("1.0e+1");
  EXPECT_TRUE(result.first);
  EXPECT_DOUBLE_EQ(10.0, result.second);
}
TEST(Test, str_to_f_scientic_minus) {
  std::pair<bool, double> result = str_to_f<double>("1.0e-1");
  EXPECT_TRUE(result.first);
  EXPECT_DOUBLE_EQ(0.1, result.second);
}
TEST(Test, str_to_f_a) {
  std::pair<bool, double> result = str_to_f<double>("a");
  EXPECT_FALSE(result.first);
}
TEST(Test, str_to_f_a0) {
  std::pair<bool, double> result = str_to_f<double>("0a");
  EXPECT_FALSE(result.first);
}
TEST(Test, str_to_f_empty) {
  std::pair<bool, double> result = str_to_f<double>("");
  EXPECT_FALSE(result.first);
}
TEST(Test, str_to_f_toolarge) {
  std::pair<bool, double> result = str_to_f<double>("1.79769e+309");
  EXPECT_FALSE(result.first);
}
TEST(Test, str_to_f_toosmall) {
  std::pair<bool, double> result = str_to_f<double>("-1.79769e+309");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_float_toolarge) {
  std::pair<bool, float> result = str_to_f<float>("3.40282e+39");
  EXPECT_FALSE(result.first);
}
TEST(Test, string_to_float_toosmall) {
  std::pair<bool, float> result = str_to_f<float>("-3.40282e+39");
  EXPECT_FALSE(result.first);
}
TEST(Test, to_string) {
  EXPECT_STREQ("0", to_string(0).c_str());
  EXPECT_STREQ("1.1", to_string(1.1).c_str());
  EXPECT_STREQ("c", to_string('c').c_str());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

