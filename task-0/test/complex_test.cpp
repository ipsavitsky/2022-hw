#define BOOST_TEST_MODULE Complex
#include <boost/test/unit_test.hpp>
#include "complex/complex.hpp"

BOOST_AUTO_TEST_CASE(equality) {
    Complex_number<int, int> a(1, 1);
    Complex_number<int, int> b(1, 1);
    Complex_number<int, int> c(1, 0);
    BOOST_CHECK_EQUAL(a, b);
    BOOST_CHECK_NE(a, c);
}