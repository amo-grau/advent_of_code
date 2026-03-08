#include <gtest/gtest.h>
#include <Bank.h>
#include <vector>

TEST(TestBank, LessThanTwoBateriesInBankRaisesException) {
  std::vector<int> bateries = {1};
  EXPECT_THROW(Bank{bateries}, std::invalid_argument);
}

TEST(TestBank, TwoBatteriesInBankProvidesCombinationOfBothValues) {
  std::vector<int> batteries = {1, 3};
  auto bank = Bank(batteries);
  auto result = bank.consumption();

  EXPECT_EQ(13, result);
}

TEST(TestBank, MaximumJoltageCombinationSelected) {
  std::vector<int> batteries = {1, 3, 1, 5};
  auto bank = Bank(batteries);

  auto result = bank.consumption();

  EXPECT_EQ(35, result);
}