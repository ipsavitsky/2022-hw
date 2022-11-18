#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

TEST(TEST_IDENT, test_func) {
    ident id;
    ASSERT_EQ(5, id(5));
}

TEST(TEST_IDENT, test_deriv) {
    ident id;
    ASSERT_EQ(1, id.get_deriv(100));
}