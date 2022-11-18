#include <stdexcept>
#include "symb_math/functions.hpp"

_const::_const(double _const_inp) : _const_val(_const_inp) {}

_const::_const(std::initializer_list<double> _const_inp) {
    if (_const_inp.size() == 1) {
        _const_val = *(_const_inp.begin());
    } else {
        throw std::invalid_argument("invalid number of arguments");
    }
}

double _const::operator()(double x) const {
    return _const_val;
}

double _const::get_deriv(double x) const {
    return 0;
}
