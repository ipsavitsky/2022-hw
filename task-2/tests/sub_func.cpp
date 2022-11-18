#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

TEST(TEST_SUB_COMP, test_func) {
    power x(2);
    power y(3);
    sub_func s(x, y);
    ASSERT_DOUBLE_EQ(-18, s(3));
}

TEST(TEST_SUB_COMP, test_deriv) {
    power x(2);
    power y(3);
    sub_func s(x, y);
    ASSERT_DOUBLE_EQ(-8, s.get_deriv(2));
}
