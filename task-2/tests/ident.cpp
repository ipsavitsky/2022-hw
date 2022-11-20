#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

TEST(TEST_IDENT, test_func) {
    ident id;
    ASSERT_DOUBLE_EQ(5, id(5));
}

TEST(TEST_IDENT, test_deriv) {
    ident id;
    ASSERT_DOUBLE_EQ(1, id.get_deriv(100));
}

TEST(TEST_IDENT, test_throw) {
    ASSERT_THROW({ ident y{1}; }, std::invalid_argument);
    // ASSERT_THROW({ _const y{1, 2, 3}; }, std::invalid_argument);
}

TEST(TEST_IDENT, test_to_string) {
    ident id;
    ASSERT_EQ(id.to_string(), "Ident x");
}

TEST(TEST_CONST, test_clone) {
    ident c;
    auto a = c.clone();
    ASSERT_DOUBLE_EQ(5, (*a)(5));
}