#include "rational/rational.hpp"
#include <cmath>

Rational_number::Rational_number(int64_t numerator, uint64_t denominator)
    : numerator(numerator), denominator(denominator) {}

Rational_number Rational_number::operator*(Rational_number second) {
    return Rational_number(numerator * second.numerator,
                           denominator * second.denominator);
}

Rational_number Rational_number::operator*=(Rational_number second) {
    numerator *= second.numerator;
    denominator *= second.denominator;
    return *this;
}

Rational_number Rational_number::operator/(Rational_number second) {
    return Rational_number(numerator * second.denominator,
                           denominator * second.numerator);
}

Rational_number Rational_number::operator/=(Rational_number second) {
    numerator *= second.denominator;
    denominator *= second.numerator;
    return *this;
}

Rational_number Rational_number::operator+(Rational_number second) {
    return Rational_number(numerator * second.denominator +
                               second.numerator * denominator,
                           denominator * second.denominator);
}

Rational_number Rational_number::operator+=(Rational_number second) {
    numerator = numerator * second.denominator + second.numerator * denominator;
    denominator *= second.denominator;
    return *this;
}

Rational_number Rational_number::operator-(Rational_number second) {
    return Rational_number(numerator * second.denominator -
                               second.numerator * denominator,
                           denominator * second.denominator);
}

Rational_number Rational_number::operator-=(Rational_number second) {
    numerator = numerator * second.denominator - second.numerator * denominator;
    denominator *= second.denominator;
    return *this;
}

int64_t Rational_number::gcd(int64_t frst, int64_t scnd) {
    frst = std::abs(frst);
    scnd = std::abs(scnd);
    while (frst != scnd) {
        if (frst > scnd) {
            frst = frst - scnd;
        } else {
            scnd = scnd - frst;
        }
    }
    return frst;
}

void Rational_number::simplify() {
    int64_t gcd_val = gcd(numerator, denominator);
    numerator /= gcd_val;
    denominator /= gcd_val;
}

bool Rational_number::operator<(Rational_number second) {
    int64_t numerator1 = numerator * second.denominator;
    int64_t numerator2 = second.numerator * denominator;
    return numerator1 < numerator2;
}

bool Rational_number::operator>(Rational_number second) {
    int64_t numerator1 = numerator * second.denominator;
    int64_t numerator2 = second.numerator * denominator;
    return numerator1 > numerator2;
}

bool Rational_number::operator<=(Rational_number second) {
    int64_t numerator1 = numerator * second.denominator;
    int64_t numerator2 = second.numerator * denominator;
    return numerator1 <= numerator2;
}

bool Rational_number::operator>=(Rational_number second) {
    int64_t numerator1 = numerator * second.denominator;
    int64_t numerator2 = second.numerator * denominator;
    return numerator1 >= numerator2;
}

bool Rational_number::operator==(Rational_number second) {
    int64_t numerator1 = numerator * second.denominator;
    int64_t numerator2 = second.numerator * denominator;
    return numerator1 == numerator2;
}

bool Rational_number::operator!=(Rational_number second) {
    int64_t numerator1 = numerator * second.denominator;
    int64_t numerator2 = second.numerator * denominator;
    return numerator1 != numerator2;
}

Rational_number &Rational_number::operator++() {
    numerator += denominator;
    return *this;
}

Rational_number Rational_number::operator++(int) {
    Rational_number prev = *this;
    ++*this;
    return prev;
}

Rational_number &Rational_number::operator--() {
    numerator -= denominator;
    return *this;
}

Rational_number Rational_number::operator--(int) {
    Rational_number prev = *this;
    --*this;
    return prev;
}

