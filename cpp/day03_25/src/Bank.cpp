#include <vector>
#include <stdexcept>
#include <Bank.h>
#include <algorithm>
#include <iostream>

Bank::Bank(std::vector<int> batteries, int active_batteries_count){
    if (batteries.size() < active_batteries_count)
        throw std::invalid_argument("...");

    Bank::batteries = batteries;
    Bank::active_batteries_count = active_batteries_count;
}

long long Bank::maximum_joltage(){
    std::vector<int> selected_indexes = {};
    select_indexes(selected_indexes, active_batteries_count - 1);
    
    std::vector<int> selected_batteries_indexes;
    for(int i = 0; i < selected_indexes.size(); i++){
        int index = selected_indexes[i];
        selected_batteries_indexes.push_back(batteries[index]);
    }

    std::cout << "selected_indexes: ";
    for (int n : selected_indexes) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    return calculate_joltage_of(selected_batteries_indexes);
}

long long Bank::calculate_joltage_of(std::vector<int> selection_of_batteries)
{
    long long result = 0;
    long long multiplier = 1;
    for (int i = selection_of_batteries.size() - 1; i >= 0; i--)
    {
        std::cout << "    multiplier: " << multiplier << " battery_joltage: " << selection_of_batteries[i] << std::endl;
        result += multiplier * selection_of_batteries[i];
        multiplier *= 10;
    }

    return result;
}

void Bank::select_indexes(std::vector<int>& current_selection, int missing_selection_amount_after_iteration){
    int selected_index = select_next_index(missing_selection_amount_after_iteration, current_selection);
    current_selection.push_back(selected_index);
    
    if (missing_selection_amount_after_iteration != 0){
        select_indexes(current_selection, missing_selection_amount_after_iteration - 1);
    }
}

int Bank::select_next_index(int missing_selection_amount_after_iteration, std::vector<int> current_selection){
    int starting_index = select_starting_index_in_iteration(current_selection);
    int selected_index = starting_index;
    
    for (int i = starting_index; i < batteries.size() - missing_selection_amount_after_iteration; i++){
        auto current_max = batteries[selected_index];
        auto current_value = batteries[i];
        
        if (current_value > current_max){
            selected_index = i;
        }
    }

    return selected_index;
}
    
int Bank::select_starting_index_in_iteration(std::vector<int> current_selection){
    if (current_selection.size() > 0){
        return current_selection.back() + 1;
    }
    return 0;
}