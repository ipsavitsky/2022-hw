#ifndef GRADIENT_DESCENT_HPP__
#define GRADIENT_DESCENT_HPP__

#include <memory>
#include "symb_math/functions.hpp"

double gradient_descent(std::shared_ptr<function> func,
                        double starting_point,
                        std::size_t am_of_iterations);

#endif