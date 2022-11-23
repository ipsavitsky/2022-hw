#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

class div_tests : public ::testing::Test {
   protected:
    power x = power(3);
    power y = power(2);
    div_func s = div_func(x, y);
};

TEST_F(div_tests, test_func) {
    EXPECT_DOUBLE_EQ(3, s(3));
}

TEST_F(div_tests, test_deriv) {
    EXPECT_DOUBLE_EQ(1, s.get_deriv(2));
}

TEST_F(div_tests, test_to_string) {
    EXPECT_EQ(s.to_string(), "(Power x^3.000000 / Power x^2.000000)");
}

TEST_F(div_tests, test_clone) {
    auto k = s.clone();
    EXPECT_DOUBLE_EQ(3, (*k)(3));
}