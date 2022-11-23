#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

class sub_tests : public ::testing::Test {
   protected:
    power x = power(2);
    power y = power(3);
    sub_func s = sub_func(x, y);
};

TEST_F(sub_tests, test_func) {
    EXPECT_DOUBLE_EQ(-18, s(3));
}

TEST_F(sub_tests, test_deriv) {
    EXPECT_DOUBLE_EQ(-8, s.get_deriv(2));
}

TEST_F(sub_tests, test_to_string) {
    EXPECT_EQ(s.to_string(), "(Power x^2.000000 - Power x^3.000000)");
}

TEST_F(sub_tests, test_clone) {
    auto k = s.clone();
    EXPECT_DOUBLE_EQ(-18, (*k)(3));
}