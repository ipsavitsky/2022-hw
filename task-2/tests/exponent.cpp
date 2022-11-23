#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

class exponent_tests : public ::testing::Test {
   protected:
    exponent exp_2 = exponent(2);
    exponent exp_5 = exponent(5);
};

TEST_F(exponent_tests, test_func) {
    EXPECT_DOUBLE_EQ(32, exp_2(5));
}

TEST_F(exponent_tests, test_deriv) {
    EXPECT_DOUBLE_EQ(40.235947810852508, exp_5.get_deriv(2));
}

TEST_F(exponent_tests, test_to_string) {
    EXPECT_EQ(exp_5.to_string(), "Exponent 5.000000^x");
}

TEST_F(exponent_tests, test_clone) {
    auto a = exp_2.clone();
    EXPECT_DOUBLE_EQ(32, (*a)(5));
}

TEST(TEST_EXPONENT, test_throw) {
    EXPECT_THROW({ exponent y{}; }, std::invalid_argument);
    // ASSERT_THROW({ _const y{1, 2, 3}; }, std::invalid_argument);
}