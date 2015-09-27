#include <stdio.h>
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <numeric>

#include "gtest/gtest.h"

namespace {

#include "p.cc"

TEST(Test, indefinite_articleTest) {

  EXPECT_STREQ("", indefinite_article("").c_str());
  EXPECT_STREQ("an", indefinite_article("America").c_str());
  EXPECT_STREQ("an", indefinite_article("amazon").c_str());
  EXPECT_STREQ("an", indefinite_article("India").c_str());
  EXPECT_STREQ("an", indefinite_article("island").c_str());
  EXPECT_STREQ("an", indefinite_article("USA").c_str());
  EXPECT_STREQ("an", indefinite_article("umbrella").c_str());
  EXPECT_STREQ("an", indefinite_article("England").c_str());
  EXPECT_STREQ("an", indefinite_article("english").c_str());
  EXPECT_STREQ("an", indefinite_article("Orange").c_str());
  EXPECT_STREQ("an", indefinite_article("orange").c_str());

  EXPECT_STREQ("a", indefinite_article("knight").c_str());
}

}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
