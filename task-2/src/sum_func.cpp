#include "symb_math/functions.hpp"

sum_func::sum_func(function& left, function& right)
    : left_r(left), right_r(right) {}

double sum_func::operator()(double x) const {
    return left_r(x) + right_r(x);
}

double sum_func::get_deriv(double x) const {
    return left_r.get_deriv(x) + right_r.get_deriv(x);
}
