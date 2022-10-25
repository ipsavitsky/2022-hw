#include "scheduling/operations.hpp"

#include <functional>
#include <random>

solution* change_processor::eval(solution* sol_to_change) {
    solution* new_solution = sol_to_change->clone();
    auto get_task = std::bind(std::uniform_int_distribution<>(0, sol_to_change->get_task_amount()),
                              std::default_random_engine());
    auto get_proc = std::bind(std::uniform_int_distribution<>(0, sol_to_change->get_proc_amount()),
                              std::default_random_engine());
    solution::task_t task_to_move = get_task();
    new_solution->remove_task(task_to_move);
    new_solution->add_task(task_to_move, get_proc());
    return new_solution;
}