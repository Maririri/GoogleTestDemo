#include "ArrayQueue.h"
#include <gtest/gtest.h>

class ArrayQueueFixture2 : public ::testing::Test {

protected:
  virtual void TearDown() {
    delete q0;
    delete q1;
  }

  virtual void SetUp() {
    q0 = new ArrayQueue();
    q1 = new ArrayQueue(2);

    q1->Enqueue(1);
  }

  ArrayQueue *q0;
  ArrayQueue *q1;
};

TEST(SuiteName, TestName) {}

TEST_F(ArrayQueueFixture2, IsEmpty) {
  EXPECT_EQ(0, q0->Size());
  EXPECT_TRUE(1 == 1);
}

TEST_F(ArrayQueueFixture2, DequeueTest) {
  //    int n = q1->Dequeue();
  //    EXPECT_EQ(1, n);
  ASSERT_TRUE(1 != 1);
  ASSERT_THROW(q1->Dequeue(), std::out_of_range);
  EXPECT_EQ(0, q1->Size());
}
