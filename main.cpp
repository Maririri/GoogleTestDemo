#include "src/Numbers.h"
#include <gtest/gtest.h>

TEST(BasicTests, NumberCompare) {
  EXPECT_EQ(1, ONE);
  EXPECT_GT(TWO, ONE);
  EXPECT_TRUE(1 == 1);
}

void f() {
  int x = 42;
  ASSERT_NEAR(x, 42.0, 1e-12);
}

TEST(BasicTests, ToString) {
  EXPECT_STREQ("one", NumbersToString(ONE));
  EXPECT_STRCASEEQ("TWO", NumbersToString(TWO));
  EXPECT_STREQ("zero", NumbersToString(0));
}

TEST(SuiteName5, TestName1) { ASSERT_TRUE(true); }

TEST(SuiteName5, TestName2) { ASSERT_TRUE(true); }

TEST(SuiteName, success1) { ASSERT_TRUE(true); }

TEST(SuiteName, success2) { ASSERT_TRUE(true); }

TEST(SuiteName, failure1) { ASSERT_TRUE(false); }

TEST(SuiteName, success3) { ASSERT_TRUE(true); }

TEST(SuiteName, failure2) { ASSERT_TRUE(false); }
