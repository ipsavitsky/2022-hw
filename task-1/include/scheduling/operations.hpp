#ifndef SCHEDULING_OPERATIONS_HPP_
#define SCHEDULING_OPERATIONS_HPP_

class operation {
    virtual void eval() = 0;
};

class change_processor : operation {
    void eval();
};

#endif