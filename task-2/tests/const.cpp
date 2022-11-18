#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

#include <stdexcept>

TEST(TEST_CONST, test_func) {
    _const t(7);
    ASSERT_DOUBLE_EQ(7, t(5));
}

TEST(TEST_CONST, test_deriv) {
    _const c(7);
    ASSERT_DOUBLE_EQ(0, c.get_deriv(100));
}

TEST(TEST_CONST, test_throw) {
    ASSERT_THROW({ _const y{}; }, std::invalid_argument);
    // ASSERT_THROW({ _const y{1, 2, 3}; }, std::invalid_argument);
}