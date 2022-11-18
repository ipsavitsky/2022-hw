#include "symb_math/functions.hpp"

div_func::div_func(function& left, function& right)
    : left_r(left), right_r(right) {}

double div_func::operator()(double x) const {
    return left_r(x) / right_r(x);
}

double div_func::get_deriv(double x) const {
    return (left_r.get_deriv(x) * right_r(x) -
            left_r(x) * right_r.get_deriv(x)) /
           (right_r(x) * right_r(x));
}
