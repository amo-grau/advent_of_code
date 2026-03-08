#pragma once
#include <vector>

class Bank {
    public:
        Bank(std::vector<int> batteries);

        int consumption();

        int calculate_joltage_of(std::vector<int> selection_of_batteries);

    private:
        std::vector<int> batteries;
        int active_batteries_count;

        void select_indexes(std::vector<int>& current_selection, int missing_selection_amount);
};