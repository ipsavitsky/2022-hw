#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

TEST(TEST_CONST, test_func) {
    _const c{7};
    ASSERT_DOUBLE_EQ(7, c(5));
}

TEST(TEST_CONST, test_deriv) {
    _const c{7};
    ASSERT_DOUBLE_EQ(0, c.get_deriv(100));
}