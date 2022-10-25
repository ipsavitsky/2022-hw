#include "scheduling/temperature.hpp"
#include <cmath>

temperature::temperature(double temp) : base_temp(temp), cur_temp(temp) {}

double temperature::get_temp() {
    return cur_temp;
}

boltzmann_temp::boltzmann_temp(double temp) : temperature(temp) {}

void boltzmann_temp::eval(std::size_t iteration) {
    cur_temp = base_temp / std::log(1 + iteration);
}

cauchy_temp::cauchy_temp(double temp) : temperature(temp) {}

void cauchy_temp::eval(std::size_t iteration) {
    cur_temp = base_temp / 1 + iteration;
}

log_div_n_temp::log_div_n_temp(double temp) : temperature(temp) {}

void log_div_n_temp::eval(std::size_t iteration) {
    cur_temp = base_temp * (std::log(1 + iteration) / (1 + iteration));
}
