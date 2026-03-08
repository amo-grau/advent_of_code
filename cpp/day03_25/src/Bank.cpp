#include <vector>
#include <stdexcept>
#include <Bank.h>
#include <algorithm>
#include <iostream>

Bank::Bank(std::vector<int> batteries){
    active_batteries_count = 2;

    if (batteries.size() < active_batteries_count)
        throw std::invalid_argument("...");
    Bank::batteries = batteries;
}

int Bank::consumption(){
    
    int selected_index_1 = 0;
    for (int i = 0; i < batteries.size() - 1; i++){
        if (i == 0){
            continue;
        }
        auto current_max = batteries[selected_index_1];
        auto current_value = batteries[i];
        
        if (current_value > current_max){
            selected_index_1 = i;
        }
    }
    
    int selected_index_2 = 0;
    for (int i = selected_index_1; i < batteries.size(); i++){
        if (i == 0){
            continue;
        }
        auto current_max = batteries[selected_index_2];
        auto current_value = batteries[i];
        
        if (current_value > current_max){
            selected_index_2 = i;
        }
    }
    
    std::vector<int> selected_batteries = {
        batteries[selected_index_1], 
        batteries[selected_index_2]
    };
    return calculate_joltage_of(selected_batteries);
}

int Bank::calculate_joltage_of(std::vector<int> selection_of_batteries)
{
    auto result = 0;
    auto multiplier = 1;
    for (int i = selection_of_batteries.size() - 1; i >= 0; i--)
    {
        result += multiplier * selection_of_batteries[i];
        multiplier *= 10;
    }

    return result;
}
