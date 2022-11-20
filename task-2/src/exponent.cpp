#include <cmath>
#include <stdexcept>
#include "symb_math/functions.hpp"

exponent::exponent(double exp_val) : exp(exp_val) {}

exponent::exponent(std::initializer_list<double> exp_val) {
    if (exp_val.size() == 1) {
        exp = *(exp_val.begin());
    } else {
        throw std::invalid_argument("invalid number of arguments");
    }
}

double exponent::operator()(double x) const {
    return std::pow(exp, x);
}

double exponent::get_deriv(double x) const {
    return std::pow(exp, x) * std::log(exp);
}

std::string exponent::to_string() const {
    return "Exponent " + std::to_string(exp) + "^x";
}

std::unique_ptr<function> exponent::clone() const {
    return std::make_unique<exponent>(*this);
}