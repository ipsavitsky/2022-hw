#ifndef SCHEDULING_ANNEALING_HPP_
#define SCHEDULING_ANNEALING_HPP_

#include "operations.hpp"
#include "temperature.hpp"

class annealing {
   private:
    operation* op;
    temperature* t;

   public:
    annealing(operation* oper, temperature* temp);

    void anneal();
};

#endif