#include <cmath>
#include <stdexcept>
#include "symb_math/functions.hpp"

power::power(double power_val) : base(power_val) {}

power::power(std::initializer_list<double> power_val) {
    if (power_val.size() == 1) {
        base = *(power_val.begin());
    } else {
        throw std::invalid_argument("invalid number of arguments");
    }
}

double power::operator()(double x) const {
    return std::pow(x, base);
}

double power::get_deriv(double x) const {
    return base * std::pow(x, base - 1);
}

std::string power::to_string() const {
    return "Power x^" + std::to_string(base);
}

std::unique_ptr<function> power::clone() const {
    return std::make_unique<power>(*this);
}