#define BOOST_TEST_MODULE Vector
#include <boost/test/unit_test.hpp>
#include "vector/cmprsd_vector.hpp"
#include "vector/exceptions.hpp"

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

BOOST_AUTO_TEST_CASE(sum_of_vectors) {
    compressed_vector<int> vec_1(5);
    vec_1(0) = 2;
    vec_1(2) = 1;
    vec_1(3) = 8;
    vec_1(4) = 9;
    compressed_vector<int> vec_2(5);
    vec_2(0) = 9;
    vec_2(1) = 8;
    vec_2(2) = 1;
    vec_2(4) = 2;
    auto res = vec_1 + vec_2;
    BOOST_CHECK_EQUAL(res(0), 11);
    BOOST_CHECK_EQUAL(res(1), 8);
    BOOST_CHECK_EQUAL(res(2), 2);
    BOOST_CHECK_EQUAL(res(3), 8);
    BOOST_CHECK_EQUAL(res(4), 11);
}