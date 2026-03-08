#include <string>
#include <vector>
#include <sstream>
#include "Bank.h"
#include "BankBuilder.h"

BankBuilder::BankBuilder(){ }

Bank BankBuilder::build_from(std::string batteries_string){
    std::vector<int> batteries_vector;
    
    for (char c : batteries_string){
        batteries_vector.push_back(c - '0');
    }

    return Bank(batteries_vector);
}

std::vector<Bank> BankBuilder::build_from_multiple(std::string banks_string){
    std::vector<Bank> banks;

    std::istringstream ss(banks_string);
    std::string line;

    while (std::getline(ss, line, '\n')){
        banks.push_back(build_from(line));
    }

    return banks;
}
