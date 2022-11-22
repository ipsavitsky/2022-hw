#include "symb_math/functions_factory.hpp"
#include "symb_math/functions.hpp"
#include "gtest/gtest.h"

TEST(TEST_TREE_COMPUTATION, test_basic) {
    functions_factory f;
    auto a = f.create_object("power", {2});
    auto b = f.create_object("ident", {});
    auto s = *a + *b;
    auto c = f.create_object("const", {6});
    auto m = s * (*c);
    ASSERT_DOUBLE_EQ(180, m(5));
}