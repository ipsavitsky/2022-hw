#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

TEST(TEST_POWER, test_func) {
    power pow_2{2};
    ASSERT_DOUBLE_EQ(25, pow_2(5));
}

TEST(TEST_POWER, test_deriv) {
    power pow_3{3};
    ASSERT_DOUBLE_EQ(12, pow_3.get_deriv(2));
}