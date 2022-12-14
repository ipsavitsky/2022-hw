#ifndef FUNCTIONS_HPP__
#define FUNCTIONS_HPP__

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <vector>

class function {
   public:
    virtual double operator()(double x) const = 0;
    virtual double get_deriv(double x) const = 0;
    virtual std::unique_ptr<function> clone() const = 0;
    virtual std::string to_string() const = 0;
    virtual ~function(){};
};

class ident : public function {
   public:
    ident() = default;
    ident(std::initializer_list<double> dummy);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
    std::unique_ptr<function> clone() const override;
    std::string to_string() const override;
};

class _const : public function {
   private:
    double _const_val;

   public:
    _const(double _const_intp);
    _const(std::initializer_list<double> _const_inp);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
    std::unique_ptr<function> clone() const override;
    std::string to_string() const override;
};

class power : public function {
   private:
    double base;

   public:
    power(double power_val);
    power(std::initializer_list<double> power_val);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
    std::unique_ptr<function> clone() const override;
    std::string to_string() const override;
};

class exponent : public function {
   private:
    double exp;

   public:
    exponent(double exp_val);
    exponent(std::initializer_list<double> exp_val);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
    std::unique_ptr<function> clone() const override;
    std::string to_string() const override;
};

class polynom : public function {
   private:
    std::vector<double> coefs;

   public:
    polynom(std::initializer_list<double> lst);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
    std::unique_ptr<function> clone() const override;
    std::string to_string() const override;
};

class sum_func : public function {
   private:
    std::unique_ptr<function> left_r, right_r;

   public:
    sum_func(const function& left, const function& right);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
    std::unique_ptr<function> clone() const override;
    std::string to_string() const override;
};

class sub_func : public function {
   private:
    std::unique_ptr<function> left_r, right_r;

   public:
    sub_func(const function& left, const function& right);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
    std::unique_ptr<function> clone() const override;
    std::string to_string() const override;
};

class mul_func : public function {
   private:
    std::unique_ptr<function> left_r, right_r;

   public:
    mul_func(const function& left, const function& right);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
    std::unique_ptr<function> clone() const override;
    std::string to_string() const override;
};

class div_func : public function {
   private:
    std::unique_ptr<function> left_r, right_r;

   public:
    div_func(const function& left, const function& right);
    double operator()(double x) const override;
    double get_deriv(double x) const override;
    std::unique_ptr<function> clone() const override;
    std::string to_string() const override;
};

template <typename T>
sum_func operator+(const function& a, const T& b) {
    if constexpr (std::is_base_of_v<function, T>) {
        return sum_func(a, b);
    } else {
        throw std::logic_error("cannot sum func with that");
    }
}

template <typename T>
sub_func operator-(const function& a, const T& b) {
    if constexpr (std::is_base_of_v<function, T>) {
        return sub_func(a, b);
    } else {
        throw std::logic_error("cannot sum func with that");
    }
}

template <typename T>
mul_func operator*(const function& a, const T& b) {
    if constexpr (std::is_base_of_v<function, T>) {
        return mul_func(a, b);
    } else {
        throw std::logic_error("cannot sum func with that");
    }
}

template <typename T>
div_func operator/(const function& a, const T& b) {
    if constexpr (std::is_base_of_v<function, T>) {
        return div_func(a, b);
    } else {
        throw std::logic_error("cannot sum func with that");
    }
}

#endif