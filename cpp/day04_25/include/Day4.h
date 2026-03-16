#include <string>
#include <vector>
#include <array>

class Day4{
public:
    int countAccessibleRolls(std::string input, int maximumContiguous);
    
    private:
        bool isAccessible(std::vector<std::vector<char>> input, int i, int j, int maximumContiguous);
        bool isInRange(std::array<int, 2UL> &direction, int i, int j, std::vector<std::vector<char>> &input);
        std::vector<std::vector<char>> parseInput(std::string input);
        bool isRoll(char element);
};