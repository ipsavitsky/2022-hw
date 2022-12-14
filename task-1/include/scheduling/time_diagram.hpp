#ifndef SCHEDULING_TIME_DIAGRAM_HPP_
#define SCHEDULING_TIME_DIAGRAM_HPP_

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class solution {
   protected:
    std::size_t proc_amount;
    std::size_t task_amount;

   public:
    solution(std::size_t pr_am, std::size_t tk_am);
    solution(const solution& other) = default;

    using task_t = std::size_t;
    using proc_t = std::size_t;

    std::size_t get_proc_amount();

    std::size_t get_task_amount();

    virtual void generate_approximation() = 0;
    virtual uint64_t calculate_target_function() = 0;
    virtual std::vector<uint64_t> get_proc_loads() = 0;
    virtual std::vector<task_t> get_tasks_on_proc(proc_t proc) = 0;
    virtual void remove_task(task_t task_to_remove) = 0;
    virtual void add_task(task_t task_to_add, proc_t proc_to_add_to) = 0;
    virtual std::shared_ptr<solution> clone() = 0;

    virtual ~solution(){};
};

class time_diagram : public solution {
   private:
    std::unordered_map<task_t, proc_t> storage;
    std::vector<std::size_t> times_vec;

   public:
    time_diagram(std::size_t pr_am,
                 std::size_t tk_am,
                 const std::vector<std::size_t>& times);
    time_diagram(const time_diagram& other) = default;

    void generate_approximation();
    uint64_t calculate_target_function();
    std::vector<uint64_t> get_proc_loads();
    std::vector<task_t> get_tasks_on_proc(proc_t proc);
    void remove_task(task_t task_to_remove);
    void add_task(task_t task_to_add, proc_t proc_to_add_to);
    std::shared_ptr<solution> clone();

    std::string stringify();
};

#endif