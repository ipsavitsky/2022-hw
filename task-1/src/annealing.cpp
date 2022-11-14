#include "scheduling/annealing.hpp"

#include <functional>
#include <iostream>
#include <random>
#include <thread>

annealing::annealing(std::shared_ptr<solution> res,
                     std::vector<std::shared_ptr<operation>> opers,
                     std::shared_ptr<temperature> temp)
    : operations(opers), t(temp), cur_best(res) {
    cur_best->generate_approximation();
    std::cout << dynamic_cast<time_diagram*>(cur_best.get())->stringify();
    std::cout << cur_best->calculate_target_function() << std::endl;
    best_target_func = cur_best->calculate_target_function();
}

void annealing::anneal(std::size_t thread_num) {
    std::random_device r;
    auto rand_oper =
        std::bind(std::uniform_int_distribution<>(0, operations.size() - 1),
                  std::default_random_engine(r()));

    auto annealing_prob = std::bind(std::uniform_real_distribution<>(0, 1),
                                    std::default_random_engine(r()));

    std::size_t iteration = 0;
    std::size_t useless_iteration = 0;
    std::size_t num_threads = thread_num;

    while (true) {
        using loop_return_value_t =
            std::pair<decltype(useless_iteration), std::shared_ptr<solution>>;

        std::vector<std::thread> threads(num_threads);
        std::vector<std::promise<loop_return_value_t>> promises(num_threads);
        std::vector<std::future<loop_return_value_t>> futures(num_threads);

        auto the_loop = [*this, &rand_oper, &annealing_prob, useless_iteration](
                            std::promise<loop_return_value_t>&& p) {
            std::size_t temp_it = 100;
            auto local_best = cur_best->clone();
            auto cur_best_func = best_target_func;
            auto local_useless_iteration = useless_iteration;
            for (uint64_t i = 0; i < temp_it; ++i) {
                std::shared_ptr<operation> op = operations[rand_oper()];
                std::shared_ptr<solution> new_solution = op->eval(local_best);
                std::size_t new_target_func =
                    new_solution->calculate_target_function();
                int64_t f_delta = new_target_func - cur_best_func;
                if (f_delta < 0) {
                    // std::cout << '1' << std::endl;
                    std::swap(local_best, new_solution);
                    cur_best_func = new_target_func;
                    local_useless_iteration = 0;
                } else {
                    // std::cout << '2' << std::endl;
                    ++local_useless_iteration;
                    double temp_cutoff =
                        std::exp(static_cast<double>(-f_delta) / t->get_temp());
                    double test = annealing_prob();
                    if (test <= temp_cutoff) {
                        std::swap(local_best, new_solution);
                        cur_best_func = new_target_func;
                    }
                }
            }
            p.set_value(std::make_pair(local_useless_iteration, local_best));
        };

        for (int i = 0; i < num_threads; ++i) {
            futures[i] = promises[i].get_future();
            threads[i] = std::thread(the_loop, std::move(promises[i]));
        }

        for (auto& th : threads) {
            th.join();
        }

        std::vector<loop_return_value_t> results(num_threads);
        std::transform(
            futures.begin(), futures.end(), results.begin(),
            [](std::future<loop_return_value_t>& a) { return a.get(); });

        auto best_sol = std::min_element(
            results.begin(), results.end(),
            [](loop_return_value_t& a, loop_return_value_t& b) {
                return a.second->calculate_target_function() <
                       b.second->calculate_target_function();
            });

        std::swap(cur_best, best_sol->second);
        useless_iteration = best_sol->first;

        if (useless_iteration > 70) {
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