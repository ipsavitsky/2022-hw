#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

class mul_tests : public ::testing::Test {
   protected:
    power x = power(2);
    power y = power(3);
    mul_func s = mul_func(x, y);
};

TEST_F(mul_tests, test_func) {
    EXPECT_DOUBLE_EQ(243, s(3));
}

TEST_F(mul_tests, test_deriv) {
    EXPECT_DOUBLE_EQ(80, s.get_deriv(2));
}

TEST_F(mul_tests, test_to_string) {
    EXPECT_EQ(s.to_string(), "(Power x^2.000000 * Power x^3.000000)");
}

TEST_F(mul_tests, test_clone) {
    auto k = s.clone();
    EXPECT_DOUBLE_EQ(243, (*k)(3));
}