#include <vector>
#include <stdexcept>
#include <Bank.h>
#include <algorithm>

Bank::Bank(std::vector<int> batteries){
    active_batteries_count = 2;

    if (batteries.size() < active_batteries_count)
        throw std::invalid_argument("...");
    Bank::batteries = batteries;
}

int Bank::consumption(){
    int result = 0;
    
    auto batteries_copy = batteries;

    for (int i = 0; i < active_batteries_count; i++){
        auto max_iterator = std::max_element(batteries_copy.begin(), batteries_copy.end());
        auto max_value = *max_iterator;
        
        result += max_value;
        batteries_copy.erase(max_iterator);
    }

    return result;
}
