#ifndef CMPRSD_VECTOR_EXCEPTIONS_HPP_
#define CMPRSD_VECTOR_EXCEPTIONS_HPP_

#include <exception>

class out_of_bounds_exception : public std::exception {};
class incorrect_dimensions : public std::exception {};

#endif