#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <cstdint>

class Rational_number {
    int64_t numerator;
    uint64_t denominator;

    public:
    Rational_number operator+(Rational_number second);
    Rational_number operator-(Rational_number second);
    Rational_number operator*(Rational_number second);
    Rational_number operator/(Rational_number second);

    bool operator<(Rational_number second);
    bool operator>(Rational_number second);
    bool operator<=(Rational_number second);
    bool operator>=(Rational_number second);
    bool operator==(Rational_number second);
    bool operator!=(Rational_number second);
    Rational_number operator++();
    Rational_number operator--();
    Rational_number operator+=(Rational_number second);
    Rational_number operator-=(Rational_number second);
    Rational_number operator*=(Rational_number second);
    Rational_number operator/=(Rational_number second);
};

#endif