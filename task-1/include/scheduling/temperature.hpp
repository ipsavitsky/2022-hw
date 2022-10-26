#ifndef SCHEDULING_TEMPERATURE_HPP_
#define SCHEDULING_TEMPERATURE_HPP_

#include <utility>

class temperature {
   protected:
    temperature(double temp);
    double base_temp, cur_temp;

   public:
    double get_temp();

    virtual void eval(std::size_t iteration) = 0;

    virtual ~temperature(){};
};

class boltzmann_temp : public temperature {
   public:
    boltzmann_temp(double temp);
    void eval(std::size_t iteration);
};

class cauchy_temp : public temperature {
   public:
    cauchy_temp(double temp);
    void eval(std::size_t iteration);
};

class log_div_n_temp : public temperature {
   public:
    log_div_n_temp(double temp);
    void eval(std::size_t iteration);
};

#endif