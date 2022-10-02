#include "rational/rational.hpp"
#include "rational/exceptions.hpp"
#include <cmath>
#include <iostream>

Rational_number::Rational_number() : numerator(0), denominator(1) {}

Rational_number::Rational_number(long int st) : numerator(st), denominator(1) {}

Rational_number::Rational_number(int64_t numerator, uint64_t denominator)
    : numerator(numerator), denominator(denominator) {
    if (0 == denominator) {
        throw zero_division_exception();
    }
}

Rational_number
Rational_number::operator*(const Rational_number &second) const {
    return Rational_number(numerator * second.numerator,
                           denominator * second.denominator);
}

Rational_number Rational_number::operator*=(Rational_number second) {
    numerator *= second.numerator;
    denominator *= second.denominator;
    return *this;
}

Rational_number
Rational_number::operator/(const Rational_number &second) const {
    return Rational_number(numerator * second.denominator,
                           denominator * second.numerator);
}

Rational_number Rational_number::operator/=(Rational_number second) {
    numerator *= second.denominator;
    denominator *= second.numerator;
    if(0 == denominator) {
        throw zero_division_exception();
    }
    return *this;
}

Rational_number
Rational_number::operator+(const Rational_number &second) const {
    return Rational_number(numerator * second.denominator +
                               second.numerator * denominator,
                           denominator * second.denominator);
}

Rational_number Rational_number::operator+=(Rational_number second) {
    numerator = numerator * second.denominator + second.numerator * denominator;
    denominator *= second.denominator;
    return *this;
}

Rational_number
Rational_number::operator-(const Rational_number &second) const {
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

void Rational_number::make_canonical() {
    int64_t gcd_val = gcd(numerator, denominator);
    numerator /= gcd_val;
    denominator /= gcd_val;
}

std::strong_ordering Rational_number::operator<=>(const Rational_number &second) const {
    int64_t numerator1 = numerator * second.denominator;
    int64_t numerator2 = second.numerator * denominator;
    return numerator1 <=> numerator2;
}

bool Rational_number::operator==(const Rational_number &second) const {
    int64_t numerator1 = numerator * second.denominator;
    int64_t numerator2 = second.numerator * denominator;
    return numerator1 == numerator2;
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

int64_t Rational_number::get_numerator() const { return numerator; }

uint64_t Rational_number::get_denominator() const { return denominator; }

Rational_number::operator int() const { return numerator / denominator; }

Rational_number::operator long int() const { return numerator / denominator; }

Rational_number::operator short() const { return numerator / denominator; }

Rational_number &Rational_number::operator=(const Rational_number &second) {
    numerator = second.numerator;
    denominator = second.denominator;
    return *this;
}

Rational_number Rational_number::floor() {
    int64_t new_numerator = numerator - (numerator % denominator);
    return Rational_number(new_numerator, denominator);
}

Rational_number Rational_number::round() {
    int64_t new_numerator = numerator - (numerator % denominator);
    if ((numerator % denominator) > (denominator / 2))
        new_numerator += denominator;
    return Rational_number(new_numerator, denominator);
}

std::ostream &operator<<(std::ostream &os, const Rational_number &rn) {
    os << rn.numerator << "/" << rn.denominator;
    return os;
}

Rational_number Rational_number::operator+(int64_t second) const {
    return Rational_number(numerator + denominator * second, denominator);
}

Rational_number Rational_number::operator-(int64_t second) const {
    return Rational_number(numerator - denominator * second, denominator);
}

Rational_number Rational_number::operator*(int64_t second) const {
    return Rational_number(numerator * second, denominator);
}

Rational_number Rational_number::operator/(int64_t second) const {
    return Rational_number(numerator, denominator * second);
}

std::strong_ordering Rational_number::operator<=>(int64_t second) const {
    return *this <=> Rational_number(second);
}

// bool Rational_number::operator<(int64_t second) const {
//     return *this < Rational_number(second);
// }

// bool Rational_number::operator>(int64_t second) const {
//     return *this > Rational_number(second);
// }

// bool Rational_number::operator<=(int64_t second) const {
//     return *this <= Rational_number(second);
// }

// bool Rational_number::operator>=(int64_t second) const {
//     return *this >= Rational_number(second);
// }

bool Rational_number::operator==(int64_t second) const {
    return *this == Rational_number(second);
}

// bool Rational_number::operator!=(int64_t second) const {
//     return *this != Rational_number(second);
// }

Rational_number Rational_number::operator+=(int64_t second) {
    this->operator+=(Rational_number(second));
    return *this;
}

Rational_number Rational_number::operator-=(int64_t second) {
    this->operator-=(Rational_number(second));
    return *this;
}

Rational_number Rational_number::operator*=(int64_t second) {
    this->operator*=(Rational_number(second));
    return *this;
}

Rational_number Rational_number::operator/=(int64_t second) {
    this->operator/=(Rational_number(second));
    return *this;
}
