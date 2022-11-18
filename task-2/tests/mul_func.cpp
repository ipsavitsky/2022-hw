#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

TEST(TEST_MUL_COMP, test_func) {
    power x(2);
    power y(3);
    mul_func s(x, y);
    ASSERT_DOUBLE_EQ(243, s(3));
}

TEST(TEST_MUL_COMP, test_deriv) {
    power x(2);
    power y(3);
    mul_func s(x, y);
    ASSERT_DOUBLE_EQ(80, s.get_deriv(2));
}
