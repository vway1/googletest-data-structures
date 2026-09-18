#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "binary_tree.h"

class MockBinaryTree : public BinaryTree {
public:
    MOCK_METHOD(void, push, (int value), (override));
    MOCK_METHOD(void, pop, (int value), (override));
    MOCK_METHOD(bool, search, (int value), (const, override));
};

TEST(BinaryTreeTest, PushAddsValue) {
    MockBinaryTree tree;

    EXPECT_CALL(tree, push(15)).Times(1);
    tree.push(15);
}

TEST(BinaryTreeTest, PopRemovesValue) {
    MockBinaryTree tree;

    EXPECT_CALL(tree, pop(15)).Times(1);
    tree.pop(15);
}

TEST(BinaryTreeTest, SearchFindsExistingValue) {
    MockBinaryTree tree;

    EXPECT_CALL(tree, search(15)).WillOnce(testing::Return(true));
    EXPECT_TRUE(tree.search(15));
}

TEST(BinaryTreeTest, SearchDoesNotFindMissingValue) {
    MockBinaryTree tree;

    EXPECT_CALL(tree, search(100)).WillOnce(testing::Return(false));
    EXPECT_FALSE(tree.search(100));
}
