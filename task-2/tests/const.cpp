#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

#include <stdexcept>

class const_tests : public ::testing::Test {
   protected:
    _const c_7 = _const(7);
};

TEST_F(const_tests, test_func) {
    EXPECT_DOUBLE_EQ(7, c_7(5));
}

TEST_F(const_tests, test_deriv) {
    EXPECT_DOUBLE_EQ(0, c_7.get_deriv(100));
}

TEST_F(const_tests, test_to_string) {
    EXPECT_EQ(c_7.to_string(), "Const 7.000000");
}

TEST_F(const_tests, test_clone) {
    auto a = c_7.clone();
    EXPECT_DOUBLE_EQ(7, (*a)(5));
}

TEST(TEST_CONST, test_throw) {
    EXPECT_THROW({ _const y{}; }, std::invalid_argument);
    // ASSERT_THROW({ _const y{1, 2, 3}; }, std::invalid_argument);
}