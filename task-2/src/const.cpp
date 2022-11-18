#include "functions.hpp"

_const::_const(double _const_inp) : _const_val(_const_inp) {}

double _const::operator()(double x) const {
    return _const_val;
}

double _const::get_deriv(double x) const {
    return 0;
}
