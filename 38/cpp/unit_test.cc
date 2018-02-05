#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "filter.h"

using namespace testing;

TEST(Test, filter_even_numbers) {
    ASSERT_TRUE((filter::filter_even_numbers(std::vector<int>{})).empty());
    ASSERT_TRUE((filter::filter_even_numbers(std::vector<int>{1})).empty());
    ASSERT_TRUE((filter::filter_even_numbers(std::vector<int>{1, 3})).empty());

    ASSERT_THAT(filter::filter_even_numbers(std::vector<int>{0}),
                ElementsAre(0));
    ASSERT_THAT(filter::filter_even_numbers(std::vector<int>{0, 1}),
                ElementsAre(0));
    ASSERT_THAT(filter::filter_even_numbers(std::vector<int>{0, 1, 2}),
                ElementsAre(0, 2));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
