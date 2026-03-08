#include <gtest/gtest.h>
#include <BankBuilder.h>
#include <Bank.h>

TEST(TestBankBuilder, StringWithTwoValues) {
    auto builder = BankBuilder();

    auto result = builder.build_from("12");

    EXPECT_EQ(Bank(std::vector<int> {1, 2}).consumption(), result.consumption());
}

TEST(TestBankBuilder, StringWithMultipleValues){
    auto builder = BankBuilder();

    auto result = builder.build_from("12345");

    EXPECT_EQ(Bank(std::vector<int> {1, 2, 3, 4, 5}).consumption(), result.consumption());
}