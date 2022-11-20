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
    return std::transform_reduce(coefs.cbegin(), coefs.cend(), 0.0, std::plus{},
                                 calc_poly);
}

double polynom::get_deriv(double x) const {
    int num = 0;
    auto calc_poly = [x, &num](double coef) mutable {
        ++num;
        return coef * num * std::pow(x, num - 1);
    };
    return std::transform_reduce(std::next(coefs.cbegin()), coefs.cend(), 0.0,
                                 std::plus{}, calc_poly);
}

std::string polynom::to_string() const {
    int num = 1;
    auto poly_fold = [&num](std::string cur, double b) mutable {
        return std::move(cur) + " + " + std::to_string(b) + "*x^" +
               std::to_string(num++);
    };
    return "Polynom " + std::accumulate(std::next(coefs.begin()), coefs.end(),
                                        std::to_string(coefs[0]), poly_fold);
}