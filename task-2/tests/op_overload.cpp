#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

class operator_test : public ::testing::Test {
   protected:
    ident id;
    power x_2 = power(2);
};

TEST_F(operator_test, test_sum) {
    auto s = id + x_2;
    sum_func s_2(id, x_2);
    EXPECT_EQ(typeid(s), typeid(s_2));
    EXPECT_DOUBLE_EQ(42, s(6));
}

TEST_F(operator_test, test_sub) {
    auto s = id - x_2;
    sub_func s_2(id, x_2);
    EXPECT_EQ(typeid(s), typeid(s_2));
    EXPECT_DOUBLE_EQ(-30, s(6));
}

TEST_F(operator_test, test_mul) {
    auto s = id * x_2;
    mul_func s_2(id, x_2);
    EXPECT_EQ(typeid(s), typeid(s_2));
    EXPECT_DOUBLE_EQ(216, s(6));
}

TEST_F(operator_test, test_div) {
    auto s = x_2 / id;
    div_func s_2(id, x_2);
    EXPECT_EQ(typeid(s), typeid(s_2));
    EXPECT_DOUBLE_EQ(6, s(6));
}

TEST_F(operator_test, sfinae_sum) {
    EXPECT_THROW({ id + "123"; }, std::logic_error);
}

TEST_F(operator_test, sfinae_sub) {
    EXPECT_THROW({ id - "123"; }, std::logic_error);
}

TEST_F(operator_test, sfinae_mul) {
    EXPECT_THROW({ id * "123"; }, std::logic_error);
}

TEST_F(operator_test, sfinae_div) {
    EXPECT_THROW({ id / "123"; }, std::logic_error);
}