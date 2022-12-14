#define BOOST_TEST_MODULE Rational
#include "rational/rational.hpp"
#include <boost/test/unit_test.hpp>
#include "rational/exceptions.hpp"

struct rationals_fixture {
    Rational_number a = Rational_number(1, 2);
    Rational_number b = Rational_number(1, 2);
    Rational_number c = Rational_number(2, 4);
};

BOOST_FIXTURE_TEST_CASE(equality, rationals_fixture) {
    BOOST_CHECK_EQUAL(a, b);
    BOOST_CHECK_EQUAL(a, c);
    Rational_number d(15, 5);
    BOOST_CHECK_EQUAL(d, 3);
}

BOOST_FIXTURE_TEST_CASE(inequality, rationals_fixture) {
    Rational_number b(1, 3);
    BOOST_CHECK_NE(a, b);
    BOOST_CHECK_NE(b, c);
    BOOST_CHECK_NE(5, c);
}

BOOST_FIXTURE_TEST_CASE(less, rationals_fixture) {
    Rational_number b(1, 3);
    BOOST_CHECK_LT(b, a);
    BOOST_CHECK_LT(b, c);
    Rational_number d(100, 200);
    BOOST_CHECK_LE(c, d);
    BOOST_CHECK_LE(-1, d);
}

BOOST_FIXTURE_TEST_CASE(greater, rationals_fixture) {
    Rational_number b(1, 3);
    BOOST_CHECK_GT(a, b);
    BOOST_CHECK_GT(c, b);
    Rational_number d(100, 200);
    BOOST_CHECK_GE(c, d);
    BOOST_CHECK_GE(1, d);
}

BOOST_FIXTURE_TEST_CASE(infex_and_postfix, rationals_fixture) {
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

BOOST_FIXTURE_TEST_CASE(round_and_floor, rationals_fixture) {
    BOOST_CHECK_EQUAL(Rational_number(0, 1), a.floor());
    Rational_number b(2, 3);
    BOOST_CHECK_EQUAL(Rational_number(1, 1), b.round());
    BOOST_CHECK_EQUAL(Rational_number(100, 3).round(), Rational_number(33, 1));
}

BOOST_AUTO_TEST_CASE(convertions_to_integral) {
    Rational_number a(1000, 12);
    BOOST_CHECK_EQUAL((int)a, 83);
    BOOST_CHECK_EQUAL((long int)a, 83);
    BOOST_CHECK_EQUAL((short)a, 83);
}

BOOST_FIXTURE_TEST_CASE(arithmetics_with_numbers, rationals_fixture) {
    a += 5;
    BOOST_CHECK_EQUAL(Rational_number(11, 2), a);
    a -= 3;
    BOOST_CHECK_EQUAL(Rational_number(5, 2), a);
    a = a * (int64_t)5;
    BOOST_CHECK_EQUAL(Rational_number(25, 2), a);
}

BOOST_AUTO_TEST_CASE(zero_div) {
    BOOST_CHECK_THROW(Rational_number(1, 0), zero_division_exception);
}