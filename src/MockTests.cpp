#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "LinkedListQueue.h"

using ::testing::AtLeast;

struct MockQueue : public LinkedListQueue {

    MOCK_CONST_METHOD0(Size, size_t());
    MOCK_METHOD1(Enqueue, void (int));

};

void EmptyQueue(LinkedListQueue &q) {
    q.Enqueue(1);

    while (q.Size() > 0) {
        q.Dequeue();
    }
}


TEST(AA, EnqueueCalledAtLeastOnce) {
    MockQueue queue;

    EXPECT_CALL(queue, Enqueue(1)).Times(AtLeast(1));

    EmptyQueue(queue);
}

TEST(MockQueue, SizeCalledAtLeastOnce) {
    MockQueue queue;

    EXPECT_CALL(queue, Size()).Times(AtLeast(1));

    EmptyQueue(queue);
}
