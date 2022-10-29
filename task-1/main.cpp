#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>

#include "scheduling/annealing.hpp"

int main() {
    std::ifstream file("input.dat");
    std::vector<std::size_t> data(std::istream_iterator<int>(file), {});
    std::shared_ptr<solution> s(new time_diagram(5, data.size(), data));
    std::vector<std::shared_ptr<operation>> opers = {
        std::make_shared<change_processor>()};
    std::shared_ptr<temperature> temp(new boltzmann_temp(0.1));

    annealing a(s, opers, temp);
    a.anneal();

    std::shared_ptr<solution> res = a.get_solution();

    std::cout << dynamic_cast<time_diagram*>(res.get())->stringify();
}