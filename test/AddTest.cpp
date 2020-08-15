#include "add.h"
#include "gtest/gtest.h"

TEST(AddTest, TestPositiveAdd)
{
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(2, 2), 5);
}

TEST(AddTest, TestNegativeAdd)
{
    EXPECT_EQ(add(-1, -2), -3);
    EXPECT_EQ(add(-2, -3), -5);
}