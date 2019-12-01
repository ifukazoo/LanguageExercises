#include "gtest/gtest.h"

#include "karvonen.h"

TEST(Test, calc_heart_rate) {
    ASSERT_EQ(calc_heart_rate(22, 65, 55), 138);
    ASSERT_EQ(calc_heart_rate(22, 65, 60), 145);
    ASSERT_EQ(calc_heart_rate(22, 65, 65), 151);
    ASSERT_EQ(calc_heart_rate(22, 65, 70), 158);
    ASSERT_EQ(calc_heart_rate(22, 65, 75), 165);
    ASSERT_EQ(calc_heart_rate(22, 65, 80), 171);
    ASSERT_EQ(calc_heart_rate(22, 65, 85), 178);
    ASSERT_EQ(calc_heart_rate(22, 65, 90), 185);
    ASSERT_EQ(calc_heart_rate(22, 65, 95), 191);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
