#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "queue.h"

class MockQueue : public Queue {
public:
    MOCK_METHOD(void, push, (int value), (override));
    MOCK_METHOD(int, pop, (), (override));
};

TEST(QueueTest, PushAddsValue) {
    MockQueue queue;

    EXPECT_CALL(queue, push(10)).Times(1);
    queue.push(10);
}

TEST(QueueTest, PopReturnsFirstValue) {
    MockQueue queue;

    EXPECT_CALL(queue, pop()).WillOnce(testing::Return(10));
    EXPECT_EQ(queue.pop(), 10);
}
