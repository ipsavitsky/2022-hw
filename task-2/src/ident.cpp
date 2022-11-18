#include "functions.hpp"

double ident::operator()(double x) const {
    return x;
}

double ident::get_deriv(double x) const {
    return 1;
}
