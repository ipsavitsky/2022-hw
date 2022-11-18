#include <cmath>
#include <stdexcept>
#include "symb_math/functions.hpp"

power::power(double power_val) : base(power_val) {}

power::power(std::initializer_list<double> power_val) {
    if (power_val.size() == 1) {
        base = *(power_val.begin());
    } else {
        throw std::runtime_error("invalid argument parameters");
    }
}

double power::operator()(double x) const {
    return std::pow(x, base);
}

double power::get_deriv(double x) const {
    return base * std::pow(x, base - 1);
}