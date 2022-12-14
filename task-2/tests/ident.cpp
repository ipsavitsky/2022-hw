#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

class ident_tests : public ::testing::Test {
   protected:
    ident id;
};

TEST_F(ident_tests, test_func) {
    EXPECT_DOUBLE_EQ(5, id(5));
}

TEST_F(ident_tests, test_deriv) {
    EXPECT_DOUBLE_EQ(1, id.get_deriv(100));
}

TEST_F(ident_tests, test_to_string) {
    EXPECT_EQ(id.to_string(), "Ident x");
}

TEST_F(ident_tests, test_clone) {
    auto a = id.clone();
    EXPECT_DOUBLE_EQ(5, (*a)(5));
}

TEST(TEST_IDENT, test_throw) {
    ASSERT_THROW({ ident y{1}; }, std::invalid_argument);
    // ASSERT_THROW({ _const y{1, 2, 3}; }, std::invalid_argument);
}