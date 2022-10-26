#ifndef SCHEDULING_ANNEALING_HPP_
#define SCHEDULING_ANNEALING_HPP_

#include <vector>
#include "operations.hpp"
#include "temperature.hpp"
#include "time_diagram.hpp"

class annealing {
   private:
    std::vector<operation*> operations;
    temperature* t;
    solution* cur_best;
    std::size_t best_target_func;

   public:
    annealing(solution* res, std::vector<operation*> opers, temperature* temp);

    void anneal();

    solution* get_solution();

    ~annealing();
};

#endif