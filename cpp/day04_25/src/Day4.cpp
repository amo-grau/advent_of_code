#include "Day4.h"
#include <sstream>

int Day4::countAccessibleRolls(std::string input, int maximumContiguous)
{
    if (input == "")
        return 0;

    auto inputGrid = parseInput(input);

    int count = 0;  
    for (int i = 0; i < inputGrid.size(); i++){
        auto row = inputGrid.at(i);
        for (int j = 0; j < row.size(); j++){
            auto element = row.at(j);
            if (isRoll(element))
                if (isAccessible(inputGrid, i, j, maximumContiguous))
                    count++;
        }
    }

    return count;
}

bool Day4::isAccessible(std::vector<std::vector<char>> input, int i, int j, int maximumContiguous)
{
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
    int contiguousCount = 0;
    
    for (int k = 0; k < directions.size(); k++){
        auto direction = directions[k];
        if (isInRange(direction, i, j, input))
        {
            auto contiguousElement = input.at(i + direction[0]).at(j + direction[1]);
            if (contiguousElement == '@')
                contiguousCount++;
        }
    }
    
    return contiguousCount < maximumContiguous;
}

bool Day4::isInRange(std::array<int, 2UL> &direction, int i, int j, std::vector<std::vector<char>> &input)
{
    return (i + direction[0] >= 0) && (i + direction[0] < input.size()) && (j + direction[1] >= 0) && (j + direction[1] < input.at(i).size());
}


bool Day4::isRoll(char element)
{
    return element == '@';
}

std::vector<std::vector<char>> Day4::parseInput(std::string input)
{
    std::vector<std::vector<char>> inputGrid;
    std::stringstream ss(input);
    for (std::string line; std::getline(ss, line);)
        inputGrid.emplace_back(line.begin(), line.end());

    return inputGrid;
}