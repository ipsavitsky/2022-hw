#ifndef SCHEDULING_ANNEALING_HPP_
#define SCHEDULING_ANNEALING_HPP_

#include <vector>
#include "operations.hpp"
#include "temperature.hpp"
#include "time_diagram.hpp"

class annealing {
   private:
    std::vector<std::shared_ptr<operation>> operations;
    std::shared_ptr<temperature> t;
    std::shared_ptr<solution> cur_best;
    std::size_t best_target_func;

   public:
    annealing(std::shared_ptr<solution> res,
              std::vector<std::shared_ptr<operation>> opers,
              std::shared_ptr<temperature> temp);

    void anneal();

    std::shared_ptr<solution> get_solution();
};

#endif