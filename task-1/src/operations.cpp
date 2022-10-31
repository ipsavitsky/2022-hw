#include "scheduling/operations.hpp"

#include <functional>
#include <iostream>
#include <random>

std::shared_ptr<solution> change_processor::eval(
    std::shared_ptr<solution> sol_to_change) {
    std::random_device r;
    auto new_solution = sol_to_change->clone();
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
    return new_solution;
}

std::shared_ptr<solution> unload_processor::eval(
    std::shared_ptr<solution> sol_to_change) {
    std::random_device r;
    auto new_solution = sol_to_change->clone();
    std::vector<uint64_t> loads = new_solution->get_proc_loads();
    auto max_load = std::max_element(loads.begin(), loads.end());
    auto most_loaded_proc = std::distance(loads.begin(), max_load);
    auto tasks_on_proc = new_solution->get_tasks_on_proc(most_loaded_proc);
    auto get_task =
        std::bind(std::uniform_int_distribution<>(0, tasks_on_proc.size() - 1),
                  std::default_random_engine(r()));
    auto task_num = tasks_on_proc[get_task()];
    auto least_load = std::min_element(loads.begin(), loads.end());
    auto least_loaded_proc = std::distance(loads.begin(), least_load);
    new_solution->remove_task(task_num);
    new_solution->add_task(task_num, least_loaded_proc);
    return new_solution;
}