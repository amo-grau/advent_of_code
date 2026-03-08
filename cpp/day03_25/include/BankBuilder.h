#include <string>
#include <Bank.h>

class BankBuilder{
    public:
        BankBuilder();
        Bank build_from(std::string batteries_string);
};