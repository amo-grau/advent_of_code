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

TEST(TestBankBuilder, BuildMultipleBanksFromText){
    auto builder = BankBuilder();

    auto result = builder.build_from_multiple("123\n45");

    EXPECT_EQ(Bank(std::vector<int> {1, 2, 3}).consumption(), result[0].consumption());
    EXPECT_EQ(Bank(std::vector<int> {4, 5}).consumption(), result[1].consumption());
}