#include <string>
#include <vector>
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