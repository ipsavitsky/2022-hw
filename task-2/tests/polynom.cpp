#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

TEST(TEST_POLYNOM, test_func) {
    polynom pol{1, 2, 3};
    ASSERT_DOUBLE_EQ(86, pol(5));
}

// 3 + 2 * x + 1 * x**2
// 2 + 2*x
TEST(TEST_POLYNOM, test_deriv) {
    polynom pol{3, 2, 1};
    ASSERT_DOUBLE_EQ(6, pol.get_deriv(2));
}

TEST(TEST_POLYNOM, test_to_string) {
    polynom pol{3, 2, 1};
    ASSERT_EQ(pol.to_string(),
              "Polynom 3.000000 + 2.000000*x^1 + 1.000000*x^2");
}