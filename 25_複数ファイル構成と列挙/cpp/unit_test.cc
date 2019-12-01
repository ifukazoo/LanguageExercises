#include "gtest/gtest.h"

#include "password_validator.h"

TEST(Test, PasswordValidator) {

  ASSERT_EQ(password_validator(""), Strength::VERY_WEAK);
  ASSERT_EQ(password_validator("1234567"), Strength::VERY_WEAK);
  ASSERT_EQ(password_validator("aaaaaaa"), Strength::WEAK);
  ASSERT_EQ(password_validator("aaaaaa@"), Strength::NORMAL);
  ASSERT_EQ(password_validator("123456@"), Strength::NORMAL);

  ASSERT_EQ(password_validator("aaaaaaaa"), Strength::NORMAL);
  ASSERT_EQ(password_validator("12345678"), Strength::NORMAL);
  ASSERT_EQ(password_validator("########"), Strength::NORMAL);
  ASSERT_EQ(password_validator("aaaaaaa8"), Strength::STRONG);
  ASSERT_EQ(password_validator("1234567a"), Strength::STRONG);
  ASSERT_EQ(password_validator("aaaaaa#8"), Strength::VERY_STRONG);
  ASSERT_EQ(password_validator("123456#a"), Strength::VERY_STRONG);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
