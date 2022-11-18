#include <cmath>
#include "symb_math/functions.hpp"
#include "stdexcept"

power::power(std::initializer_list<double> power_val) {
    if (power_val.size() == 1) {
        base = *(power_val.begin());
    }
    else {
        throw std::runtime_error("invalid argument parameters");
    }
}

double power::operator()(double x) const {
    return std::pow(x, base);
}

double power::get_deriv(double x) const {
    return base * std::pow(x, base - 1);
}