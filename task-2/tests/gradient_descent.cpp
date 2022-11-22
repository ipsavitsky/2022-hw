#include "symb_math/gradient_descent.hpp"
#include <cmath>
#include "gtest/gtest.h"
#include "symb_math/functions_factory.hpp"

TEST(TEST_GRAD_DESC, basic_test) {
    functions_factory f;
    auto x = f.create_object("polynom", {6, -5, 1});
    double l = gradient_descent(*x, 0.0, 100000);
    // EXPECT_DOUBLE_EQ(l, 2) << "precision not achieved";
    ASSERT_TRUE(std::fabs(l - 2) < 1e-3);
}