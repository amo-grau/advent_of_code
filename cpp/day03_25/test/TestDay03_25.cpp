#include <gtest/gtest.h>

// The function we want to test
int add(int a, int b) { return a + b; }

// Test suite: "MathTest", test name: "AddsTwoPositives"
TEST(MathTest, AddsTwoPositives) {
  EXPECT_EQ(add(2, 3), 5);
  EXPECT_EQ(add(0, 0), 0);
}

TEST(MathTest, HandlesNegativeNumbers) {
  EXPECT_EQ(add(-1, -1), -2);
  EXPECT_EQ(add(-5, 3),  -2);
}