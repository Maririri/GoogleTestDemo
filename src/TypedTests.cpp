#include "ArrayQueue.h"
#include "LinkedListQueue.h"
#include <gtest/gtest.h>

template <class T> Queue *CreateQueue();

template <> Queue *CreateQueue<ArrayQueue>() { return new ArrayQueue(10000); }

template <> Queue *CreateQueue<LinkedListQueue>() {
  return new LinkedListQueue;
}

template <class T> class QueueTypeTest : public testing::Test {
protected:
  QueueTypeTest() : q0(CreateQueue<T>()), q1(CreateQueue<T>()) {
    q1->Enqueue(1);
  }

  virtual ~QueueTypeTest() { delete q0; }

  Queue *const q0;
  Queue *const q1;
};

TYPED_TEST_CASE_P(QueueTypeTest);

TYPED_TEST_P(QueueTypeTest, IsEmpty) { EXPECT_EQ(0, this->q0->Size()); }

TYPED_TEST_P(QueueTypeTest, Dequeue) {
  int n = 0;
  ASSERT_NO_THROW(n = this->q1->Dequeue());
  EXPECT_EQ(1, n);
}

REGISTER_TYPED_TEST_CASE_P(QueueTypeTest, IsEmpty, Dequeue);

typedef testing::Types<ArrayQueue, LinkedListQueue> QueueImplementations;

INSTANTIATE_TYPED_TEST_CASE_P(ArrayAndLinkedListQueues, // Instance name
                              QueueTypeTest,            // Test case name
                              QueueImplementations);
