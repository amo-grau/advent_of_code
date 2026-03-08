#include <gtest/gtest.h>
#include <BankBuilder.h>
#include <Bank.h>

TEST(TestBankBuilder, StringWithTwoValues) {
    auto builder = BankBuilder();

    auto result = builder.build_from("12");

    EXPECT_EQ(Bank(std::vector<int> {1, 2}).consumption(), result.consumption());
}