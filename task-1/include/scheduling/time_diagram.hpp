#ifndef SCHEDULING_TIME_DIAGRAM_HPP_
#define SCHEDULING_TIME_DIAGRAM_HPP_

#include <cstddef>
#include <unordered_map>

class solution {};

class time_diagram : solution {
   public:
    using task_t = std::size_t;
    using proc_t = std::size_t;

    std::unordered_map<task_t, proc_t> storage;
};

#endif