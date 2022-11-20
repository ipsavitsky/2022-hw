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

TEST(TEST_SUB_COMP, test_to_string) {
    power x(3);
    power y(2);
    sub_func s(x, y);
    ASSERT_EQ(s.to_string(), "(Power x^3.000000 - Power x^2.000000)");
}

TEST(TEST_SUB_COMP, test_clone) {
    power x(2);
    power y(3);
    sub_func s(x, y);
    auto k = s.clone();
    ASSERT_DOUBLE_EQ(-18, (*k)(3));
}