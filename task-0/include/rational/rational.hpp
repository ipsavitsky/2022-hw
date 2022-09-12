#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <cstdint>
#include <iostream>

class Rational_number {
    int64_t gcd(int64_t frst, int64_t scnd);
    int64_t numerator;
    uint64_t denominator;

  public:

    Rational_number(int64_t numerator, uint64_t denominator);
    Rational_number operator+(const Rational_number &second) const;
    Rational_number operator-(const Rational_number &second) const;
    Rational_number operator*(const Rational_number &second) const;
    Rational_number operator/(const Rational_number &second) const;

    bool operator<(const Rational_number &second) const;
    bool operator>(const Rational_number &second) const;
    bool operator<=(const Rational_number second) const;
    bool operator>=(const Rational_number &second) const;
    bool operator==(const Rational_number &second) const;
    bool operator!=(const Rational_number &second) const;

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

    friend std::ostream &operator<<(std::ostream &os,
                                    const Rational_number &rn);
};

#endif