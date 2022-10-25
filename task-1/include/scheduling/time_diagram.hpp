#ifndef SCHEDULING_TIME_DIAGRAM_HPP_
#define SCHEDULING_TIME_DIAGRAM_HPP_

#include <cstddef>
#include <cstdint>
#include <unordered_map>

class solution {
   private:
    std::size_t proc_amount;

   public:
    virtual void generate_approximation() = 0;
    virtual uint64_t calculate_target_function() = 0;
};

class time_diagram : solution {
   public:
    using task_t = std::size_t;
    using proc_t = std::size_t;

    std::unordered_map<task_t, proc_t> storage;
    void generate_approximation();
    uint64_t calculate_target_function();
};

#endif