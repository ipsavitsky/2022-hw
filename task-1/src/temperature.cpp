#include "temperature.hpp"
#include <cmath>

temperature::temperature(double temp) : base_temp(temp) {}

boltzmann_temp::boltzmann_temp(double temp) : temperature(temp) {}

double boltzmann_temp::eval(std::size_t iteration) {
    return base_temp / std::log(1 + iteration);
}

cauchy_temp::cauchy_temp(double temp) : temperature(temp) {}

double cauchy_temp::eval(std::size_t iteration) {
    return base_temp / 1 + iteration;
}

log_div_n_temp::log_div_n_temp(double temp) : temperature(temp) {}

double log_div_n_temp::eval(std::size_t iteration) {
    return base_temp * (std::log(1 + iteration) / (1 + iteration));
}
