#include "symb_math/functions.hpp"

sub_func::sub_func(function& left, function& right)
    : left_r(left), right_r(right) {}

double sub_func::operator()(double x) const {
    return left_r(x) - right_r(x);
}

double sub_func::get_deriv(double x) const {
    return left_r.get_deriv(x) - right_r.get_deriv(x);
}
