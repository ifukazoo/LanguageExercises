#include "gtest/gtest.h"

#include "calculator.h"

TEST(Test, calculate_months_until_paid_off) {

  ASSERT_EQ(calculate_months_until_paid_off(5000, 12, 100), 70);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
