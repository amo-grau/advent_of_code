#pragma once
#include <vector>

class Bank {
    public:
        Bank(std::vector<int> batteries);

        int maximum_joltage();

        int calculate_joltage_of(std::vector<int> selection_of_batteries);

    private:
        std::vector<int> batteries;
        int active_batteries_count;

        void select_indexes(std::vector<int>& current_selection, int missing_selection_amount);
        int select_next_index(int missing_selection_amount_after_iteration, std::vector<int> current_selection);
        int select_starting_index_in_iteration(std::vector<int> current_selection);
};