#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

class polynom_test : public ::testing::Test {
   protected:
    polynom pol = polynom{3, 2, 1};
};

TEST_F(polynom_test, test_func) {
    EXPECT_DOUBLE_EQ(38, pol(5));
}

// 3 + 2 * x + 1 * x**2
// 2 + 2*x
TEST_F(polynom_test, test_deriv) {
    EXPECT_DOUBLE_EQ(6, pol.get_deriv(2));
}

TEST_F(polynom_test, test_to_string) {
    EXPECT_EQ(pol.to_string(),
              "Polynom 3.000000 + 2.000000*x^1 + 1.000000*x^2");
}

TEST_F(polynom_test, test_clone) {
    auto a = pol.clone();
    EXPECT_DOUBLE_EQ(38, (*a)(5));
}