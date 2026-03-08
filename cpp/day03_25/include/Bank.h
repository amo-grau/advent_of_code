class Bank {
    public:
        Bank(std::vector<int> batteries);

        int consumption();

    private:
        std::vector<int> batteries;
        int active_batteries_count;
};