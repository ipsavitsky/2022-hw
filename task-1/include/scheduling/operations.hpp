#ifndef SCHEDULING_OPERATIONS_HPP_
#define SCHEDULING_OPERATIONS_HPP_

#include "time_diagram.hpp"

class operation {
   public:
    virtual solution* eval(solution* sol_to_change) = 0;
};

class change_processor : public operation {
   public:
    solution* eval(solution* sol_to_change);
};

#endif