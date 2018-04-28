#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "strings.h"

using namespace testing;

TEST(Test, trim) {
    ASSERT_THAT(strings::trim(std::string("")), Eq(""));
    ASSERT_THAT(strings::trim(std::string("a")), Eq("a"));
    ASSERT_THAT(strings::trim(std::string(" a")), Eq("a"));
    ASSERT_THAT(strings::trim(std::string("a ")), Eq("a"));
    ASSERT_THAT(strings::trim(std::string(" a ")), Eq("a"));
    ASSERT_THAT(strings::trim(std::string("  a  ")), Eq("a"));
    ASSERT_THAT(strings::trim(std::string("a a  ")), Eq("a a"));
    ASSERT_THAT(strings::trim(std::string("  a a")), Eq("a a"));
    ASSERT_THAT(strings::trim(std::string("\ta\v\n")), Eq("a"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
