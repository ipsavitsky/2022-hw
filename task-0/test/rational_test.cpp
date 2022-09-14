#define BOOST_TEST_MODULE Rational test
#include "rational/rational.hpp"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(equality) {
    Rational_number a(1, 2);
    Rational_number b(1, 2);
    BOOST_CHECK_EQUAL(a, b);
    Rational_number c(2, 4);
    BOOST_CHECK_EQUAL(a, c);
}

BOOST_AUTO_TEST_CASE(inequality) {
    Rational_number a(1, 2);
    Rational_number b(1, 3);
    BOOST_CHECK_NE(a, b);
    Rational_number c(2, 4);
    BOOST_CHECK_NE(b, c);
}

BOOST_AUTO_TEST_CASE(less) {
    Rational_number a(1, 2);
    Rational_number b(1, 3);
    BOOST_CHECK_LT(b, a);
    Rational_number c(2, 4);
    BOOST_CHECK_LT(b, c);
    Rational_number d(100, 200);
    BOOST_CHECK_LE(c, d);
}

BOOST_AUTO_TEST_CASE(greater) {
    Rational_number a(1, 2);
    Rational_number b(1, 3);
    BOOST_CHECK_GT(a, b);
    Rational_number c(2, 4);
    BOOST_CHECK_GT(c, b);
    Rational_number d(100, 200);
    BOOST_CHECK_GE(c, d);
}

BOOST_AUTO_TEST_CASE(infex_and_postfix) {
    Rational_number a(1, 2);
    ++a;
    BOOST_CHECK_EQUAL(Rational_number(3, 2), a);
    BOOST_CHECK_EQUAL(Rational_number(3, 2), a++);
    BOOST_CHECK_EQUAL(Rational_number(5, 2), a);
    BOOST_CHECK_EQUAL(Rational_number(5, 2), a--);
    BOOST_CHECK_EQUAL(Rational_number(3, 2), a);
    --a;
    BOOST_CHECK_EQUAL(Rational_number(1, 2), a);
}

BOOST_AUTO_TEST_CASE(simplification) {
    Rational_number a(100, 200);
    a.make_canonical();
    BOOST_CHECK_EQUAL(1, a.get_numerator());
    BOOST_CHECK_EQUAL(2, a.get_denominator());
    Rational_number b(-12, 10);
    b.make_canonical();
    BOOST_CHECK_EQUAL(-6, b.get_numerator());
    BOOST_CHECK_EQUAL(5, b.get_denominator());
}
