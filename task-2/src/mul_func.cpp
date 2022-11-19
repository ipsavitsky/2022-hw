#include "symb_math/functions.hpp"

mul_func::mul_func(const function& left, const function& right)
    : left_r(left), right_r(right) {}

double mul_func::operator()(double x) const {
    return left_r(x) * right_r(x);
}

double mul_func::get_deriv(double x) const {
    return left_r.get_deriv(x) * right_r(x) + left_r(x) * right_r.get_deriv(x);
}
