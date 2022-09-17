#include "complex/complex.hpp"

template <typename type_real, typename type_imag>
Complex_number<type_real, type_imag>::Complex_number(type_real real,
                                                     type_imag imag)
    : rl(real), im(imag) {}