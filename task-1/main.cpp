#include <fstream>
#include <iostream>
#include <iterator>

#include "scheduling/annealing.hpp"

int main() {
    std::ifstream file("input.dat");
    std::vector<std::size_t> data(std::istream_iterator<int>(file), {});
    solution* s = new time_diagram(5, data.size(), data);
    std::vector<operation*> opers = {new change_processor()};
    temperature* temp = new boltzmann_temp(0.1);

    annealing a(s, opers, temp);
    a.anneal();
    solution* res = a.get_solution();
    std::cout << dynamic_cast<time_diagram*>(res)->stringify();

    delete temp;
    delete res;
    for (auto& a : opers) {
        delete a;
    }
}