#define BOOST_TEST_MODULE Complex
#include "complex/complex.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(equality) {
    Complex_number<int, int> a(1, 1);
    Complex_number<int, int> b(1, 1);
    Complex_number<int, int> c(1, 0);
    BOOST_CHECK_EQUAL(a, b);
    BOOST_CHECK_NE(a, c);
}