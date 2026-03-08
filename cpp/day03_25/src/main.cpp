#include <iostream>
#include "BankBuilder.h"

int main(){
    std::string input = R"(987654321111111
811111111111119
234234234234278
818181911112111)";
    
    auto banks = BankBuilder().build_from_multiple(input);
    auto result = 0;
    for (int i = 0; i < banks.size(); i++){
        result += banks[i].maximum_joltage();
    }

    std::cout << result << std::endl;
}