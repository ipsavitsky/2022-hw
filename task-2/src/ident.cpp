#include <initializer_list>
#include <stdexcept>
#include "symb_math/functions.hpp"

ident::ident(std::initializer_list<double> dummy) {
    if (dummy.size() != 0) {
        throw std::runtime_error("invalid num of args");
    }
}

double ident::operator()(double x) const {
    return x;
}

double ident::get_deriv(double x) const {
    return 1;
}
