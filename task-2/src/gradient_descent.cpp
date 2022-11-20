#include "symb_math/gradient_descent.hpp"

#include <cmath>
#include <iostream>

double gradient_descent(std::shared_ptr<function> func,
                        double starting_point,
                        std::size_t am_of_iterations) {
    constexpr double eps = 0.001;
    double lambda = 1e-5;
    double cur_point = starting_point;
    for (std::size_t i = 0; i < am_of_iterations; ++i) {
        // std::cout << "i = " << i << "; cur_point = " << cur_point
        //           << "; func(cur_point) = " << (*func)(cur_point) << std::endl;
        cur_point = cur_point + ((*func)(cur_point) > 0 ? -lambda : +lambda) *
                                    func->get_deriv(cur_point);
        if (std::fabs((*func)(cur_point)) < 0) {
            std::cerr << "breaking on proximity" << std::endl;
            break;
        }
        // lambda /= 2;
    }
    return cur_point;
}