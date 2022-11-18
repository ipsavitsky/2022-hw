#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

TEST(TEST_EXPONENT, test_func) {
    exponent exp_2{2};
    ASSERT_DOUBLE_EQ(32, exp_2(5));
}

TEST(TEST_EXPONENT, test_deriv) {
    exponent exp_5{5};
    ASSERT_DOUBLE_EQ(40.235947810852508, exp_5.get_deriv(2));
}