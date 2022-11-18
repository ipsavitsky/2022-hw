#include <cmath>
#include <numeric>
#include <stdexcept>
#include "symb_math/functions.hpp"

polynom::polynom(std::initializer_list<double> lst) {
    coefs = std::move(std::vector<double>(lst.begin(), lst.end()));
}

double polynom::operator()(double x) const {
    int num = 0;
    auto calc_poly = [x, &num](double coef) mutable {
        return coef * std::pow(x, num++);
    };
    return std::transform_reduce(coefs.cbegin(), coefs.cend(), 0, std::plus{},
                                 calc_poly);
}

double polynom::get_deriv(double x) const {
    throw std::runtime_error("not implemented");
}