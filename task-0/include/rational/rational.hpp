#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <cstdint>

class Rational_number {
    int64_t gcd(int64_t frst, int64_t scnd);

  public:
    int64_t numerator;
    uint64_t denominator;

    Rational_number(int64_t numerator, uint64_t denominator);
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

    Rational_number operator++(int);
    Rational_number operator--(int);
    Rational_number &operator++();
    Rational_number &operator--();
    Rational_number operator+=(Rational_number second);
    Rational_number operator-=(Rational_number second);
    Rational_number operator*=(Rational_number second);
    Rational_number operator/=(Rational_number second);

    void simplify();
    int64_t round();
    int64_t floor();
};

#endif