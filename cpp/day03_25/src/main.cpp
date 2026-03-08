#include <iostream>
#include "BankBuilder.h"

int main(){
    std::string input = "987654321111111\n811111111111119\n234234234234278\n818181911112111";
    
    auto banks = BankBuilder().build_from_multiple(input);
    auto result = 0;
    for (int i = 0; i < banks.size(); i++){
        result += banks[i].consumption();
    }

    std::cout << result << std::endl;
}