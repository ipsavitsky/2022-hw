#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_
#include <concepts>
#include <iostream>

template <typename T>
concept num_like = std::regular<T> && std::three_way_comparable<T>;

template <num_like type_real = double, num_like type_imag = type_real>
class Complex_number {
   private:
    type_real rl;
    type_imag im;

    auto calc_absolute_sq() { return rl * rl + im * im; }

   public:
    Complex_number(type_real real, type_imag imag) : rl(real), im(imag) {}

    Complex_number<type_real, type_imag> operator+(
        const Complex_number<type_real, type_imag>& other) const {
        Complex_number<type_real, type_imag> res = *this;
        res += other;
        return res;
    }

    Complex_number<type_real, type_imag> operator-(
        const Complex_number<type_real, type_imag>& other) const {
        Complex_number<type_real, type_imag> res = *this;
        res -= other;
        return res;
    }

    Complex_number<type_real, type_imag> operator+=(
        const Complex_number<type_real, type_real>& other) {
        rl += other.rl;
        im += other.im;
        return *this;
    }

    Complex_number<type_real, type_imag> operator-=(
        const Complex_number<type_real, type_imag>& other) {
        rl -= other.rl;
        im -= other.rl;
        return *this;
    }

    Complex_number<type_real, type_imag> operator*(
        const Complex_number<type_real, type_imag>& other) const {
        Complex_number<type_real, type_imag> res = *this;
        res *= other;
        return res;
    }

    Complex_number<type_real, type_imag> operator*=(
        const Complex_number<type_real, type_imag>& other) {
        rl = rl * other.rl - im * other.im;
        im = rl * other.im + im * other.rl;
        return *this;
    }

    Complex_number<type_real, type_imag> operator/(
        const Complex_number<type_real, type_imag>& other) const {
        Complex_number<type_real, type_imag> res = *this;
        res /= other;
        return res;
    }

    Complex_number<type_real, type_imag> operator/=(
        const Complex_number<type_real, type_imag>& other) {
        auto denominator = other.rl * other.rl + other.im * other.im;
        rl = (rl * other.rl + im * other.im) / denominator;
        im = (other.rl * im - rl * other.im) / denominator;
        return *this;
    }

    Complex_number<type_real, type_imag>& operator++() {
        ++rl;
        return *this;
    }

    Complex_number<type_real, type_imag> operator++(int) {
        Complex_number<type_real, type_imag> res = *this;
        ++rl;
        return res;
    }

    Complex_number<type_real, type_imag>& operator--() {
        --rl;
        return *this;
    }

    Complex_number<type_real, type_imag> operator--(int) {
        Complex_number<type_real, type_imag> res = *this;
        --rl;
        return res;
    }

    std::strong_ordering operator<=>(
        const Complex_number<type_real, type_imag>& other) const {
        return calc_absolute_sq() <=> other.calc_absolute_sq();
    }

    bool operator==(const Complex_number<type_real, type_imag>& other) const {
        return (rl == other.rl) && (im == other.im);
    }

    template <typename type_r, typename type_i>
    friend std::ostream& operator<<(std::ostream& str,
                                    const Complex_number<type_r, type_i>& g);
};

template <typename type_real, typename type_imag>
std::ostream& operator<<(std::ostream& str,
                         const Complex_number<type_real, type_imag>& g) {
    str << '<' << g.rl << ',' << g.im << '>';
    return str;
}

#endif