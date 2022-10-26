#include "scheduling/annealing.hpp"

#include <functional>
#include <iostream>
#include <random>

annealing::annealing(solution* res,
                     std::vector<operation*> opers,
                     temperature* temp)
    : operations{opers}, t(temp), cur_best(res) {
    cur_best->generate_approximation();
    best_target_func = cur_best->calculate_target_function();
}

void annealing::anneal() {
    std::random_device r;
    auto rand_oper =
        std::bind(std::uniform_int_distribution<>(0, operations.size() - 1),
                  std::default_random_engine(r()));

    auto annealing_prob = std::bind(std::uniform_real_distribution<>(0, 1),
                                    std::default_random_engine(r()));

    std::size_t iteration = 0;
    std::size_t useless_iteration = 0;
    std::size_t temp_it = 100;
    while (true) {
        for (uint64_t i = 0; i < temp_it; ++i) {
            operation* op = operations[rand_oper()];
            solution* new_solution = op->eval(cur_best);
            std::size_t new_target_func =
                new_solution->calculate_target_function();
            int64_t f_delta = new_target_func - best_target_func;
            if (f_delta < 0) {
                std::swap(cur_best, new_solution);
                delete new_solution;
                best_target_func = new_target_func;
                useless_iteration = 0;
            } else {
                ++useless_iteration;
                double temp_cutoff =
                    std::exp(static_cast<double>(-f_delta) / t->get_temp());
                if (annealing_prob() <= temp_cutoff) {
                    std::swap(cur_best, new_solution);
                    delete new_solution;
                    best_target_func = new_target_func;
                }
            }
        }

        if (useless_iteration > 100) {
            break;
        }

        ++iteration;
        t->eval(iteration);
    }
}

solution* annealing::get_solution() {
    return cur_best->clone();
}

annealing::~annealing() {
    delete cur_best;
}