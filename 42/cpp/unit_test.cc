#include <iostream>
#include <sstream>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "csv.h"

using namespace testing;

TEST(Test, split) {
    ASSERT_THAT(csv::split("a"), Eq(csv::Record{"a"}));
    ASSERT_THAT(csv::split("a "), Eq(csv::Record{"a "}));
    ASSERT_THAT(csv::split("a,b"), Eq(csv::Record{"a", "b"}));
    ASSERT_THAT(csv::split("a,,  "), Eq(csv::Record{"a", "", "  "}));
    ASSERT_THAT(csv::split("a,,  \n"), Eq(csv::Record{"a", "", "  \n"}));
    ASSERT_THAT(csv::split(""), Eq(csv::Record{}));
}
TEST(Test, read_csv) {
    std::vector<csv::Record> result;
    auto is = std::istringstream("a,b\nc,d,e\n");
    csv::read_csv(is, result);
    ASSERT_THAT(result,
                Eq(std::vector<csv::Record>{csv::Record{"a", "b"},
                                            csv::Record{"c", "d", "e"}}));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
