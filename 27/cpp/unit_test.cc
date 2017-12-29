#include "gtest/gtest.h"

#include "validator.h"

TEST(Test, validate_name) {
    ASSERT_EQ(validate_name(""), false);
    ASSERT_EQ(validate_name("a"), false);
    ASSERT_EQ(validate_name("aa"), true);
}

TEST(Test, validate_employee_id) {
    ASSERT_EQ(validate_empoyee_id("AA-1234"), true);
    ASSERT_EQ(validate_empoyee_id("zz-0000"), true);

    ASSERT_EQ(validate_empoyee_id(" AA-1234"), false);
    ASSERT_EQ(validate_empoyee_id(""), false);
    ASSERT_EQ(validate_empoyee_id("AA-1234 "), false);
    ASSERT_EQ(validate_empoyee_id("AA-1234\n"), false);

    ASSERT_EQ(validate_empoyee_id("12-1234"), false);
    ASSERT_EQ(validate_empoyee_id("-1234"), false);
    ASSERT_EQ(validate_empoyee_id("A-1234"), false);
    ASSERT_EQ(validate_empoyee_id("AAA-1234"), false);
    ASSERT_EQ(validate_empoyee_id("A1-1234"), false);

    ASSERT_EQ(validate_empoyee_id("AA 1234"), false);
    ASSERT_EQ(validate_empoyee_id("AA1234"), false);

    ASSERT_EQ(validate_empoyee_id("AA-aaaa"), false);
    ASSERT_EQ(validate_empoyee_id("AA-"), false);
    ASSERT_EQ(validate_empoyee_id("AA-234"), false);
    ASSERT_EQ(validate_empoyee_id("AA-12345"), false);
    ASSERT_EQ(validate_empoyee_id("AA-A234"), false);
}
TEST(Test, validate_zipcode) {
    ASSERT_EQ(validate_zipcode("0"), true);
    ASSERT_EQ(validate_zipcode("1"), true);
    ASSERT_EQ(validate_zipcode("01"), true);
    ASSERT_EQ(validate_zipcode(""), false);
    ASSERT_EQ(validate_zipcode("a"), false);
    ASSERT_EQ(validate_zipcode("g"), false);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
