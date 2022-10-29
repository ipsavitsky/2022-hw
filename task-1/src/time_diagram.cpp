#include "scheduling/time_diagram.hpp"

#include <functional>
#include <random>
#include <sstream>

solution::solution(std::size_t pr_am, std::size_t tk_am)
    : proc_amount(pr_am), task_amount(tk_am) {}

std::size_t solution::get_proc_amount() {
    return proc_amount;
}

std::size_t solution::get_task_amount() {
    return task_amount;
}

time_diagram::time_diagram(std::size_t pr_am,
                           std::size_t tk_am,
                           const std::vector<std::size_t>& times)
    : solution(pr_am, tk_am), times_vec(times) {}

void time_diagram::generate_approximation() {
    std::random_device r;
    auto proc_generator =
        std::bind(std::uniform_int_distribution<>(0, proc_amount - 1),
                  std::default_random_engine(r()));
    for (task_t i = 0; i < task_amount; ++i) {
        storage[i] = proc_generator();
    }
}

uint64_t time_diagram::calculate_target_function() {
    std::vector<uint64_t> sums(proc_amount);
    for (auto binding = storage.begin(); binding != storage.end(); ++binding) {
        sums[binding->second] += times_vec[binding->first];
    }
    return *std::max_element(sums.begin(), sums.end());
}

void time_diagram::remove_task(task_t task_to_remove) {
    storage.erase(task_to_remove);
}

void time_diagram::add_task(task_t task_to_add, proc_t proc_to_add_to) {
    storage[task_to_add] = proc_to_add_to;
}

std::shared_ptr<solution> time_diagram::clone() {
    return std::shared_ptr<solution>{new time_diagram(*this)};
}

std::string time_diagram::stringify() {
    std::stringstream ss;
    for (proc_t i = 0; i < proc_amount; ++i) {
        ss << '[' << i << "] ";
        for (auto binding : storage) {
            if (binding.second == i) {
                ss << binding.first << "; ";
            }
        }
        ss << std::endl;
    }
    return ss.str();
}