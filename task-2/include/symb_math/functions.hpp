#ifndef FUNCTIONS_HPP__
#define FUNCTIONS_HPP__

#include <initializer_list>
#include <vector>

class function {
   public:
    virtual double operator()(double x) const = 0;
    virtual double get_deriv(double x) const = 0;
    virtual ~function();
};

class ident : public function {
   public:
    double operator()(double x) const override;
    double get_deriv(double x) const override;
};

class _const : public function {
   private:
    const double _const_val;

   public:
    _const(double _const_inp);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
};

class power : public function {
   private:
    const double base;

   public:
    power(double power_val);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
};

class exponent : public function {
   private:
    const double exp;

   public:
    exponent(double exp_val);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
};

class polynom : public function {
   private:
    std::vector<double> coefs;

   public:
    polynom(std::initializer_list<double> lst);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
};

#endif