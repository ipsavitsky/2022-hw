#include "scheduling/annealing.hpp"

#include <functional>
#include <random>

annealing::annealing(solution* res,
                     std::vector<operation*> opers,
                     temperature* temp)
    : operations{opers}, t(temp), cur_best(res) {
    cur_best->generate_approximation();
    best_target_func = cur_best->calculate_target_function();
}

void annealing::anneal() {
    auto rand_oper =
        std::bind(std::uniform_int_distribution<>(0, operations.size()),
                  std::default_random_engine());

    auto annealing_prob = std::bind(std::uniform_int_distribution<>(0, 100),
                                    std::default_random_engine());

    std::size_t iteration = 0;
    std::size_t useless_iteration = 0;
    while (true) {
        operation* op = operations[rand_oper()];
        solution* new_solution = op->eval(cur_best);
        std::size_t new_target_func = new_solution->calculate_target_function();
        if (best_target_func >= new_target_func) {
            double temp_cutoff =
                std::exp(-(new_target_func - best_target_func) / t->get_temp());
            if (annealing_prob() < temp_cutoff) {
                std::swap(cur_best, new_solution);
                delete new_solution;
            }
            ++useless_iteration;
        } else {
            std::swap(cur_best, new_solution);
            delete new_solution;
            useless_iteration = 0;
        }

        if (useless_iteration > 100) {
            break;
        }

        t->eval(iteration);
        ++iteration;
    }
}