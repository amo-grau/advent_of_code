#include <gtest/gtest.h>
#include <Day4.h>

void assertAccessibleRollsIn(std::string text_input, int expectedAccessibleRolls, int maximumContiguousRolls = 9)
{
    Day4 rollCounter;
    EXPECT_EQ(expectedAccessibleRolls, rollCounter.countAccessibleRolls(text_input, maximumContiguousRolls));
}

TEST(TestDay4, OnEmptyString){
    std::string text_input = "";
    assertAccessibleRollsIn(text_input, 0);
} 

TEST(TestDay4, OneElementNotRoll){
    std::string text_input = ".";
    assertAccessibleRollsIn(text_input, 0);
}

TEST(TestDay4, OneRoll){
    std::string text_input = "@";
    assertAccessibleRollsIn(text_input, 1);
}

TEST(TestDay4, OnTwoRolls){
    std::string text_input = "@@";
    assertAccessibleRollsIn(text_input, 2);
}

TEST(TestDay4, CantPickWhenNoContiguousRolls){
    int maximumContiguous = 0;
    std::string text_input = "@";
    assertAccessibleRollsIn(text_input, 0, maximumContiguous);
}

TEST(TestDay4, CantPickWhenOneContiguousRolls){
    int maximumContiguous = 1;
    std::string text_input = "@@";
    assertAccessibleRollsIn(text_input, 0, maximumContiguous);
}

TEST(TestDay4, TwoContiguousAndOneSingle){
    int maximumContiguous = 1;
    std::string text_input = "@.@@";
    assertAccessibleRollsIn(text_input, 1, maximumContiguous);
}

TEST(TestDay4, TwoContiguousVertically){
    std::string text_input = R"(@
@)";
    assertAccessibleRollsIn(text_input, 2);
}

TEST(TestDay4, TwoContiguousVerticallyMaxOne){
    int maximumContiguous = 1;
    std::string text_input = R"(@
@)";
    assertAccessibleRollsIn(text_input, 0, maximumContiguous);
}


TEST(TestDay4, WithDiaglonalTopRight){
    int maximumContiguous = 2;
    std::string text_input = R"(.@
@.
@.)";
    assertAccessibleRollsIn(text_input, 2, maximumContiguous);
}


TEST(TestDay4, WithDiaglonalBottomRight){
    int maximumContiguous = 2;
    std::string text_input = R"(.@
@.
.@)";
    assertAccessibleRollsIn(text_input, 2, maximumContiguous);
}

TEST(TestDay4, WithDiaglonalBottomLeft){
    int maximumContiguous = 2;
    std::string text_input = R"(.@
.@
@.)";
    assertAccessibleRollsIn(text_input, 2, maximumContiguous);
}

TEST(TestDay4, WithDiaglonalTopLeft){
    int maximumContiguous = 2;
    std::string text_input = R"(@.
.@
@.)";
    assertAccessibleRollsIn(text_input, 2, maximumContiguous);
}

TEST(TestDay4, Integration){
    int maximumContiguous = 4;
    std::string text_input = R"(..@@.@@@@.
@@@.@.@.@@
@@@@@.@.@@
@.@@@@..@.
@@.@@@@.@@
.@@@@@@@.@
.@.@.@.@@@
@.@@@.@@@@
.@@@@@@@@.
@.@.@@@.@.)";
    assertAccessibleRollsIn(text_input, 13, maximumContiguous); 
}