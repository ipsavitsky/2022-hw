#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

class power_tests : public ::testing::Test {
   protected:
    power pow_2 = power(2);
    power pow_3 = power(3);
};

TEST_F(power_tests, test_func) {
    EXPECT_DOUBLE_EQ(25, pow_2(5));
}

TEST_F(power_tests, test_deriv) {
    EXPECT_DOUBLE_EQ(12, pow_3.get_deriv(2));
}

TEST_F(power_tests, test_throw) {
    EXPECT_THROW({ power y{}; }, std::invalid_argument);
    // ASSERT_THROW({ _const y{1, 2, 3}; }, std::invalid_argument);
}

TEST_F(power_tests, test_to_string) {
    EXPECT_EQ(pow_3.to_string(), "Power x^3.000000");
}

TEST_F(power_tests, test_clone) {
    auto a = pow_2.clone();
    EXPECT_DOUBLE_EQ(25, (*a)(5));
}