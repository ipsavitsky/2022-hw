#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>

#include "scheduling/annealing.hpp"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "not enough arguments";
        return 0;
    }
    std::ifstream file(argv[1]);
    std::vector<std::size_t> data;
    std::string cur_time;
    while (std::getline(file, cur_time, ',')) {
        data.push_back(std::stoi(cur_time));
    }
    std::shared_ptr<solution> s(
        new time_diagram(std::strtol(argv[2], nullptr, 10), data.size(), data));
    std::vector<std::shared_ptr<operation>> opers = {
        std::make_shared<unload_processor>(),
        std::make_shared<change_processor>()};
    std::shared_ptr<temperature> temp(
        new log_div_n_temp(std::strtod(argv[3], nullptr)));

    annealing a(s, opers, temp);
    a.anneal();

    std::shared_ptr<solution> res = a.get_solution();

    std::cout << dynamic_cast<time_diagram*>(res.get())->stringify();
    std::cout << res->calculate_target_function() << std::endl;
    return 0;
}