#include "scheduling/operations.hpp"

#include <functional>
#include <iostream>
#include <random>

solution* change_processor::eval(solution* sol_to_change) {
    std::random_device r;
    solution* new_solution = sol_to_change->clone();
    auto get_task = std::bind(std::uniform_int_distribution<>(
                                  0, sol_to_change->get_task_amount() - 1),
                              std::default_random_engine(r()));
    auto get_proc = std::bind(std::uniform_int_distribution<>(
                                  0, sol_to_change->get_proc_amount() - 1),
                              std::default_random_engine(r()));
    solution::task_t task_to_move = get_task();
    new_solution->remove_task(task_to_move);
    solution::proc_t proc_to_move = get_proc();
    new_solution->add_task(task_to_move, proc_to_move);
    // std::cout << "moved task " << task_to_move << " to proc " << proc_to_move
    //           << std::endl;
    return new_solution;
}