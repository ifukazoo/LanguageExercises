#include <stdio.h>
#include "gtest/gtest.h"

TEST(Test, nothing_to_test) {
  EXPECT_TRUE(true);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
