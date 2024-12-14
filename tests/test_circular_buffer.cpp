#include <gtest/gtest.h>
#include "../include/circular_buffer.h"

TEST(CircularBufferTest, PushAndPop) {
    CircularBuffer<int> buffer(3);
    buffer.push(1);
    buffer.push(2);
    buffer.push(3);

    EXPECT_EQ(buffer.pop(), 1);
    EXPECT_EQ(buffer.pop(), 2);
    EXPECT_EQ(buffer.pop(), 3);
}

TEST(CircularBufferTest, Overflow) {
    CircularBuffer<int> buffer(2);
    buffer.push(1);
    buffer.push(2);

    EXPECT_THROW(buffer.push(3), std::overflow_error);
}

TEST(CircularBufferTest, Underflow) {
    CircularBuffer<int> buffer(2);

    EXPECT_THROW(buffer.pop(), std::underflow_error);
}
