#include "ArrayQueue.h"
#include <gtest/gtest.h>

class ArrayQueueFixture : public ::testing::Test {

public:
  virtual ~ArrayQueueFixture() {}

protected:
  virtual void TearDown() {
    delete q0;
    delete q1;
  }

  virtual void SetUp() {
    q0 = new ArrayQueue();
    q1 = new ArrayQueue();

    q1->Enqueue(1);
  }

  ArrayQueue *q0;
  ArrayQueue *q1;
};

class LAlala : public ::testing::Test {};

#define MACRO

MACRO // TEST_F

    TEST_F(ArrayQueueFixture, IsEmpty) { // one
  EXPECT_EQ(0, q0->Size());
}

TEST_F(ArrayQueueFixture, DequeueTest) {
  int n = q1->Dequeue();

  //    ASSERT_EQ(1,2);
  EXPECT_EQ(1, n);
  EXPECT_THROW(q1->Dequeue(), std::out_of_range);
}

#define TEST_M(test_fixture, test_name)                                        \
  GTEST_TEST_(test_fixture, test_name, test_fixture,                           \
              ::testing::internal::GetTypeId<test_fixture>())

TEST_M(ArrayQueueFixture, name) {}