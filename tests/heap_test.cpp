#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "heap.h"

class MockHeap : public Heap {
public:
    MOCK_METHOD(void, push, (int value), (override));
    MOCK_METHOD(int, pop, (), (override));
};

TEST(HeapTest, PushAddsValue) {
    MockHeap heap;

    EXPECT_CALL(heap, push(25)).Times(1);
    heap.push(25);
}

TEST(HeapTest, PopReturnsMaximumValue) {
    MockHeap heap;

    EXPECT_CALL(heap, pop()).WillOnce(testing::Return(25));
    EXPECT_EQ(heap.pop(), 25);
}
