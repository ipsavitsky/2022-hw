#include "symb_math/functions.hpp"

mul_func::mul_func(const function& left, const function& right)
    : left_r(left.clone()), right_r(right.clone()) {}

double mul_func::operator()(double x) const {
    return (*left_r)(x) * (*right_r)(x);
}

double mul_func::get_deriv(double x) const {
    return left_r->get_deriv(x) * (*right_r)(x) +
           (*left_r)(x)*right_r->get_deriv(x);
}

std::string mul_func::to_string() const {
    return "(" + left_r->to_string() + " * " + right_r->to_string() + ")";
}

std::unique_ptr<function> mul_func::clone() const {
    return std::make_unique<mul_func>(*left_r, *right_r);
}