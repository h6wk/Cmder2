/******************************************************************************
 * @Author                : h6wk<h6wking@gmail.com>                           *
 * @CreatedDate           : 2023-07-31 20:37:54                               *
 * @LastEditDate          : 2023-07-31 20:37:57                               *
 * @CopyRight             : GNU GPL                                           *
 *****************************************************************************/

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}