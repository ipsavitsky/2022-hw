#include "gtest/gtest.h"
#include "symb_math/functions.hpp"
#include "symb_math/functions_factory.hpp"

TEST(TEST_PERSISTANCE, basic_test) {
    functions_factory f;
    auto inner_scope = [&f]() -> sum_func {
        auto a = f.create_object("ident", {});
        auto b = f.create_object("const", {5});
        return *a + *b;
    };
    auto outer_scope = inner_scope();
    ASSERT_DOUBLE_EQ(15, outer_scope(10));
}