#include <cmath>
#include "functions.hpp"

power::power(double power_val) : base(power_val) {}

double power::operator()(double x) const {
    return std::pow(x, base);
}

double power::get_deriv(double x) const {
    return base * std::pow(x, base - 1);
}