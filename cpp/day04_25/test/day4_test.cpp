#include <gtest/gtest.h>
#include "day4_test.h"

bool isAccessible(std::vector<std::vector<char>> input, int i, int j, int maximumContiguous)
{
    if (maximumContiguous == 9)
        return true;
    if (maximumContiguous == 0)
        return false;
    
    int contiguousCount = 0;

    std::vector<std::array<int, 2>> directions {
        { 0, -1},
        { 0,  1},
        {-1,  0},
        { 1,  0},
        {-1,  1},
        { 1,  1},
        { 1, -1},
        {-1, -1},
    };
    for (int k = 0; k < directions.size(); k++){
        auto direction = directions[k];
        if ((i + direction[0] >= 0) && (i + direction[0] < input.size())
            && (j + direction[1] >= 0) && (j + direction[1] < input.at(i).size())
        ){
            auto contiguousElement = input.at(i + direction[0]).at(j + direction[1]);
            if (contiguousElement == '@')
                contiguousCount++;
        }
    }

    return contiguousCount < maximumContiguous;
}

int count_accessible_rolls(std::string input, int maximumContiguous){
    if (input == "")
        return 0;
    std::vector<std::vector<char>> inputGrid;
    std::stringstream ss(input);
    for (std::string line; std::getline(ss, line);)
        inputGrid.emplace_back(line.begin(), line.end());
    

    int count = 0;  
    for (int i = 0; i < inputGrid.size(); i++){
        auto row = inputGrid.at(i);
        for (int j = 0; j < row.size(); j++){
            auto element = row.at(j);
            if (element == '@')
                if (isAccessible(inputGrid, i, j, maximumContiguous))
                    count++;
        }
    }
    
    return count;
}

void assertAccessibleRollsIn(std::string text_input, int expectedAccessibleRolls, int maximumContiguousRolls = 9)
{
    EXPECT_EQ(expectedAccessibleRolls, count_accessible_rolls(text_input, maximumContiguousRolls));
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