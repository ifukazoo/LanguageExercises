#include <stdio.h>
#include "gtest/gtest.h"

#include <limits>

#include "functions.h"

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
TEST(Test, string_to_char_toosmall) {
  std::pair<bool, float> result = str_to_f<float>("-3.40282e+39");
  EXPECT_FALSE(result.first);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
