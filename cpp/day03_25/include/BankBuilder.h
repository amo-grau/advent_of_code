#include <string>
#include <vector>
#include <Bank.h>

class BankBuilder{
    public:
        BankBuilder();
        Bank build_from(std::string batteries_string);
        std::vector<Bank> build_from_multiple(std::string banks_string);
};