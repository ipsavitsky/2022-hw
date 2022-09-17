#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_
#include <iostream>

template <typename type_real, typename type_imag> class Complex_number {
  private:
    type_real rl;
    type_imag im;

    auto calc_absolute_sq() { return rl * rl + im * im; }

  public:
    Complex_number(type_real real, type_imag imag) : rl(real), im(imag) {}

    Complex_number<type_real, type_imag>
    operator+(const Complex_number<type_real, type_imag> &other) const {
        return Complex_number(rl + other.rl, im + other.im);
    }

    Complex_number<type_real, type_imag>
    operator-(const Complex_number<type_real, type_imag> &other) const {
        return Complex_number(rl - other.rl, im - other.im);
    }

    Complex_number<type_real, type_imag>
    operator+=(const Complex_number<type_real, type_real> &other) {
        rl += other.rl;
        im += other.im;
        return *this;
    }

    Complex_number<type_real, type_imag>
    operator-=(const Complex_number<type_real, type_imag> &other) {
        rl -= other.rl;
        im -= other.rl;
        return *this;
    }

    Complex_number<type_real, type_imag>
    operator*(const Complex_number<type_real, type_imag> &other) const {
        return Complex_number(rl * other.rl - im * other.im,
                              rl * other.im + im * other.rl);
    }

    Complex_number<type_real, type_imag>
    operator*=(const Complex_number<type_real, type_imag> &other) {
        rl = rl * other.rl - im * other.im;
        im = rl * other.im + im * other.rl;
        return *this;
    }

    Complex_number<type_real, type_imag>
    operator/(const Complex_number<type_real, type_imag> &other) const {
        auto denominator = other.rl * other.rl + other.im * other.im;
        return Complex_number((rl * other.rl + im * other.im) / denominator,
                              (other.rl * im - rl * other.im) / denominator);
    }

    Complex_number<type_real, type_imag>
    operator/=(const Complex_number<type_real, type_imag> &other) {
        auto denominator = other.rl * other.rl + other.im * other.im;
        rl = (rl * other.rl + im * other.im) / denominator;
        im = (other.rl * im - rl * other.im) / denominator;
        return *this;
    }

    Complex_number<type_real, type_imag> &operator++() {
        ++rl;
        return *this;
    }

    Complex_number<type_real, type_imag> operator++(int) {
        Complex_number<type_real, type_imag> res = *this;
        ++rl;
        return res;
    }

    Complex_number<type_real, type_imag> &operator--() {
        --rl;
        return *this;
    }

    Complex_number<type_real, type_imag> operator--(int) {
        Complex_number<type_real, type_imag> res = *this;
        --rl;
        return res;
    }

    bool operator==(const Complex_number<type_real, type_imag> &other) const {
        return (rl == other.rl) && (im == other.im);
    }

    bool operator!=(const Complex_number<type_real, type_imag> &other) const {
        return (rl != other.rl) || (im != other.im);
    }

    bool operator<(const Complex_number<type_real, type_imag> &other) const {
        return calc_absolute_sq() < other.calc_absolute_sq();
    }

    bool operator>(const Complex_number<type_real, type_imag> &other) const {
        return calc_absolute_sq() > other.calc_absolute_sq();
    }

    bool operator<=(const Complex_number<type_real, type_imag> &other) const {
        return calc_absolute_sq() <= other.calc_absolute_sq();
    }

    bool operator>=(const Complex_number<type_real, type_imag> &other) const {
        return calc_absolute_sq() >= other.calc_absolute_sq();
    }

    template <typename type_r, typename type_i>
    friend std::ostream &operator<<(std::ostream &str,
                                    const Complex_number<type_r, type_i> &g);
};

template <typename type_real, typename type_imag>
std::ostream &operator<<(std::ostream &str,
                         const Complex_number<type_real, type_imag> &g) {
    str << '<' << g.rl << ',' << g.im << '>';
    return str;
}

#endif