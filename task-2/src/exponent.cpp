#include <cmath>
#include "symb_math/functions.hpp"

exponent::exponent(double exp_val) : exp(exp_val) {}

double exponent::operator()(double x) const {
    return std::pow(exp, x);
}

double exponent::get_deriv(double x) const {
    return std::pow(exp, x) * std::log(exp);
}