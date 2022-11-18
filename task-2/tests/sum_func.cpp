#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

TEST(TEST_SUM_COMP, test_func) {
    power x(2);
    power y(3);
    sum_func s(x, y);
    ASSERT_DOUBLE_EQ(36, s(3));
}

TEST(TEST_SUM_COMP, test_deriv) {
    power x(2);
    power y(3);
    sum_func s(x, y);
    ASSERT_DOUBLE_EQ(16, s.get_deriv(2));
}
