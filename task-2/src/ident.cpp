#include <initializer_list>
#include <stdexcept>
#include "symb_math/functions.hpp"

ident::ident(std::initializer_list<double> dummy) {
    if (dummy.size() != 0) {
        throw std::invalid_argument("invalid number of arguments");
    }
}

double ident::operator()(double x) const {
    return x;
}

double ident::get_deriv(double x) const {
    return 1;
}

std::string ident::to_string() const {
    return "Ident x";
}
