#include "symb_math/functions_factory.hpp"
#include "gtest/gtest.h"

TEST(TEST_FACTORY, test_funcs_creation) {
    functions_factory f;
    auto id_a = f.create_object("ident", {});
    ident id_b{};
    ASSERT_EQ(typeid(*id_a), typeid(id_b));

    auto pow_a = f.create_object("power", {4});
    power pow_b{5};
    ASSERT_EQ(typeid(*pow_a), typeid(pow_b));

    auto e_a = f.create_object("exponent", {12});
    exponent e_b{12};
    ASSERT_EQ(typeid(*e_a), typeid(e_b));

    auto c_a = f.create_object("const", {1});
    _const c_b{67};
    ASSERT_EQ(typeid(*c_a), typeid(c_b));

    auto pol_a = f.create_object("polynom", {3, 4, 1, 2, 3});
    polynom pol_b{3, 4, 5};
    ASSERT_EQ(typeid(*pol_a), typeid(pol_b));

    auto nptr = f.create_object("blah_blah_blah", {});
    ASSERT_EQ(nptr, nullptr);
}
