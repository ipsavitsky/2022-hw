#include "gtest/gtest.h"
#include "symb_math/functions.hpp"
#include "symb_math/functions_factory.hpp"

TEST(TEST_TREE_COMPUTATION, test_basic) {
    functions_factory f;
    auto a = f.create_object("power", {2});
    auto b = f.create_object("ident", {});
    auto s = *a + *b;
    auto c = f.create_object("const", {6});
    auto m = s * (*c);
    EXPECT_DOUBLE_EQ(180, m(5));
}