#include "gtest/gtest.h"
#include "symb_math/functions.hpp"

TEST(TEST_OPERATOR, test_sum) {
    ident id;
    power x_2(2);
    auto s = id + x_2;
    sum_func s_2(id, x_2);
    ASSERT_EQ(typeid(s), typeid(s_2));
    ASSERT_DOUBLE_EQ(42, s(6));
}

TEST(TEST_OPERATOR, test_sub) {
    ident id;
    power x_2(2);
    auto s = id - x_2;
    sub_func s_2(id, x_2);
    ASSERT_EQ(typeid(s), typeid(s_2));
    ASSERT_DOUBLE_EQ(-30, s(6));
}

TEST(TEST_OPERATOR, test_mul) {
    ident id;
    power x_2(2);
    auto s = id * x_2;
    mul_func s_2(id, x_2);
    ASSERT_EQ(typeid(s), typeid(s_2));
    ASSERT_DOUBLE_EQ(216, s(6));
}

TEST(TEST_OPERATOR, test_div) {
    ident id;
    power x_2(2);
    auto s = x_2 / id;
    div_func s_2(id, x_2);
    ASSERT_EQ(typeid(s), typeid(s_2));
    ASSERT_DOUBLE_EQ(6, s(6));
}

TEST(TEST_OPERTAOR, sfinae_sum) {
    ident id;
    ASSERT_THROW({ id + "123"; }, std::logic_error);
}

TEST(TEST_OPERTAOR, sfinae_sub) {
    ident id;
    ASSERT_THROW({ id - "123"; }, std::logic_error);
}

TEST(TEST_OPERTAOR, sfinae_mul) {
    ident id;
    ASSERT_THROW({ id * "123"; }, std::logic_error);
}

TEST(TEST_OPERTAOR, sfinae_div) {
    ident id;
    ASSERT_THROW({ id / "123"; }, std::logic_error);
}