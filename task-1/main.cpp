#include <iostream>

#include "scheduling/annealing.hpp"

int main() {
    solution* s = new time_diagram(20, 1000);
    std::vector<operation*> opers = {new change_processor()};
    temperature* temp = new boltzmann_temp(100);

    annealing a(s, opers, temp);
    a.anneal();
    solution* res = a.get_solution();
    std::cout << dynamic_cast<time_diagram*>(res)->stringify();
}