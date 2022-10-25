#ifndef SCHEDULING_TEMPERATURE_HPP_
#define SCHEDULING_TEMPERATURE_HPP_

#include <utility>

class temperature {
   protected:
    temperature(double temp);
    double base_temp;

   public:
    virtual double eval(std::size_t iteration) = 0;
};

class boltzmann_temp : public temperature {
   public:
    boltzmann_temp(double temp);
    double eval(std::size_t iteration);
};

class cauchy_temp : public temperature {
   public:
    cauchy_temp(double temp);
    double eval(std::size_t iteration);
};

class log_div_n_temp : public temperature {
   public:
    log_div_n_temp(double temp);
    double eval(std::size_t iteration);
};

#endif