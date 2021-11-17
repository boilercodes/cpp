//
// This is a generated example file that is supposed to be modified.
//

#include <gtest/gtest.h>

int add(int i, int j) { return i + j; }

TEST(test_add, BasicAssertions) {
  // Expect equality.
  EXPECT_EQ(add(2, 2), 4);
}
