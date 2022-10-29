#ifndef SCHEDULING_OPERATIONS_HPP_
#define SCHEDULING_OPERATIONS_HPP_

#include "time_diagram.hpp"

class operation {
   public:
    virtual std::shared_ptr<solution> eval(
        std::shared_ptr<solution> sol_to_change) = 0;
    virtual ~operation(){};
};

class change_processor : public operation {
   public:
    std::shared_ptr<solution> eval(std::shared_ptr<solution> sol_to_change);
};

#endif