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

TEST(TEST_CONST, test_to_string) {
    _const c(7);
    ASSERT_EQ(c.to_string(), "Const 7.000000");
}

TEST(TEST_CONST, test_clone) {
    _const c(7);
    auto a = c.clone();
    ASSERT_DOUBLE_EQ(7, (*a)(5));
}