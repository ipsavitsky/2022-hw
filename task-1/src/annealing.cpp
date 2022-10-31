#include "scheduling/annealing.hpp"

#include <functional>
#include <iostream>
#include <random>

annealing::annealing(std::shared_ptr<solution> res,
                     std::vector<std::shared_ptr<operation>> opers,
                     std::shared_ptr<temperature> temp)
    : operations(opers), t(temp), cur_best(res) {
    cur_best->generate_approximation();
    std::cout << dynamic_cast<time_diagram*>(cur_best.get())->stringify();
    std::cout << cur_best->calculate_target_function() << std::endl;
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
    std::size_t temp_it = 5;
    while (true) {
        for (uint64_t i = 0; i < temp_it; ++i) {
            std::shared_ptr<operation> op = operations[rand_oper()];
            std::shared_ptr<solution> new_solution = op->eval(cur_best);
            std::size_t new_target_func =
                new_solution->calculate_target_function();
            int64_t f_delta = new_target_func - best_target_func;
            if (f_delta < 0) {
                // std::cout << '1' << std::endl;
                std::swap(cur_best, new_solution);
                best_target_func = new_target_func;
                useless_iteration = 0;
            } else {
                // std::cout << '2' << std::endl;
                ++useless_iteration;
                double temp_cutoff =
                    std::exp(static_cast<double>(-f_delta) / t->get_temp());
                double test = annealing_prob();
                if (test <= temp_cutoff) {
                    std::swap(cur_best, new_solution);
                    best_target_func = new_target_func;
                }
            }
        }

        if (useless_iteration > 100) {
            break;
        }

        if (iteration % 10000) {
            std::cout << "cur_targ_func = "
                      << cur_best->calculate_target_function() << std::endl;
                    //   << "temp_cache = " << temp_cache << std::endl;
        }

        ++iteration;
        t->eval(iteration);
    }
}

std::shared_ptr<solution> annealing::get_solution() {
    return cur_best;
}