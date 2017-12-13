#include "gtest/gtest.h"

#include "anagram.h"

TEST(Test, is_anagram_Test) {
  ASSERT_TRUE(is_anagram(std::string("note"), std::string("tone")));
  ASSERT_FALSE(is_anagram(std::string("note"), std::string("Note")));
  ASSERT_FALSE(is_anagram(std::string("note"), std::string("tonee")));
  ASSERT_FALSE(is_anagram(std::string("note"), std::string("ton")));
  ASSERT_FALSE(is_anagram(std::string("note"), std::string("")));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
