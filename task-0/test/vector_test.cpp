#define BOOST_TEST_MODULE Vector
#include "vector/exceptions.hpp"
#include "vector/cmprsd_vector.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(out_of_bounds) {
    compressed_vector<int> vec(5);
    BOOST_CHECK_THROW(vec(100), out_of_bounds_exception);
}

BOOST_AUTO_TEST_CASE(element_access) {
    compressed_vector<int> vec(5);
    vec(0) = 3;
    BOOST_CHECK_EQUAL(vec(0), 3);
    BOOST_CHECK_EQUAL(vec(1), 0);
}