#include "symb_math/functions.hpp"

div_func::div_func(const function& left, const function& right)
    : left_r(left.clone()), right_r(right.clone()) {}

double div_func::operator()(double x) const {
    return (*left_r)(x) / (*right_r)(x);
}

double div_func::get_deriv(double x) const {
    return (left_r->get_deriv(x) * (*right_r)(x) -
            (*left_r)(x)*right_r->get_deriv(x)) /
           ((*right_r)(x) * (*right_r)(x));
}

std::string div_func::to_string() const {
    return "(" + left_r->to_string() + " / " + right_r->to_string() + ")";
}

std::unique_ptr<function> div_func::clone() const {
    return std::make_unique<div_func>(*left_r, *right_r);
}
