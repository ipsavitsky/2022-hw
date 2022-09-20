#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <cstdint>
#include <iostream>

/**
 * @brief 
 * 
 */
class Rational_number {
    int64_t gcd(int64_t frst, int64_t scnd);
    int64_t numerator;
    uint64_t denominator;

  public:
    /**
     * @brief Construct a new Rational_number object
     *
     */
    Rational_number();

    /**
     * @brief Construct a new Rational_number object
     *
     * @param st Number to initialize with
     */
    Rational_number(long int st);

    /**
     * @brief Construct a new Rational_number object
     *
     * @param numerator numerator of initialized rational number
     * @param denominator denominator of initialized rational number
     */
    Rational_number(int64_t numerator, uint64_t denominator);

    /**
     * @brief Overload of operator +. Returns sum of two rational numbers.
     *
     * @param second Rational number to sum with
     * @return Rational_number
     */
    Rational_number operator+(const Rational_number &second) const;

    /**
     * @brief Overload of operator -. Returns substract of two rational numbers.
     *
     * @param second Rational number to substract
     * @return Rational_number
     */
    Rational_number operator-(const Rational_number &second) const;

    /**
     * @brief Overload of operator *. Returns product of two rational numbers.
     *
     * @param second Rational number to multiply with
     * @return Rational_number
     */
    Rational_number operator*(const Rational_number &second) const;

    /**
     * @brief Overload of operator /. Returns sum of two rational numbers.
     *
     * @param second Rational number to divide by
     * @return Rational_number
     */
    Rational_number operator/(const Rational_number &second) const;

    /**
     * @brief Overload of operator +. Returns sum of a rational number and an
     * integer.
     *
     * @param second Integer to sum with
     * @return Rational_number
     */

    Rational_number operator+(int64_t second) const;

    /**
     * @brief Overload of operator -. Returns substract of a rational number and
     * an integer.
     *
     * @param second Integer to substract
     * @return Rational_number
     */
    Rational_number operator-(int64_t second) const;

    /**
     * @brief Overload of operator *. Returns product of a rational number and
     * an integer.
     *
     * @param second Integer to multiply by
     * @return Rational_number
     */
    Rational_number operator*(int64_t second) const;

    /**
     * @brief Overload of operator /. Returns division of two rational numbers.
     *
     * @param second Integer to divide by
     * @return Rational_number
     */
    Rational_number operator/(int64_t second) const;

    /**
     * @brief Overload of operator <. Compares two rational numbers.
     *
     * @param second Rational number to compare to
     * @return true
     * @return false
     */
    bool operator<(const Rational_number &second) const;

    /**
     * @brief Overload of operator >. Compares two rational numbers.
     *
     * @param second Rational number to compare to
     * @return true
     * @return false
     */
    bool operator>(const Rational_number &second) const;

    /**
     * @brief Overload of operator <=. Compares two rational numbers.
     *
     * @param second Rational number to compare to
     * @return true
     * @return false
     */
    bool operator<=(const Rational_number &second) const;

    /**
     * @brief Overload of operator >=. Compares two rational numbers.
     *
     * @param second Rational number to compare to
     * @return true
     * @return false
     */
    bool operator>=(const Rational_number &second) const;

    /**
     * @brief Overload of operator ==. Compares two rational numbers.
     *
     * @param second Rational number to compare to
     * @return true
     * @return false
     */
    bool operator==(const Rational_number &second) const;

    /**
     * @brief Overload of operator !=. Compares two rational numbers.
     *
     * @param second Rational number to compare to
     * @return true
     * @return false
     */
    bool operator!=(const Rational_number &second) const;

    /**
     * @brief Overload of operator <. Compares a rational number and an integer.
     *
     * @param second Integer to compare to
     * @return true
     * @return false
     */
    bool operator<(int64_t second) const;

    /**
     * @brief Overload of operator >. Compares a rational number and an integer.
     *
     * @param second Integer to compare to
     * @return true
     * @return false
     */
    bool operator>(int64_t second) const;

    /**
     * @brief Overload of operator <=. Compares a rational number and an
     * integer.
     *
     * @param second Integer to compare to
     * @return true
     * @return false
     */
    bool operator<=(int64_t second) const;

    /**
     * @brief Overload of operator >=. Compares a rational number and an
     * integer.
     *
     * @param second Integer to compare to
     * @return true
     * @return false
     */
    bool operator>=(int64_t second) const;

    /**
     * @brief Overload of operator ==. Compares a rational number and an
     * integer.
     *
     * @param second Integer to compare to
     * @return true
     * @return false
     */
    bool operator==(int64_t second) const;

    /**
     * @brief Overload of operator !=. Compares a rational number and an
     * integer.
     *
     * @param second Integer to compare to
     * @return true
     * @return false
     */
    bool operator!=(int64_t second) const;

    /**
     * @brief Overload of postfix iterator ++. Increments a rational number.
     *
     * @return Rational_number
     */
    Rational_number operator++(int);

    /**
     * @brief Overload of postfix operator --. Decrements a rational number.
     *
     * @return Raational_number
     */
    Rational_number operator--(int);

    /**
     * @brief Overload of prefix operator ++. Increments a rational number.
     *
     * @return Rational_number&
     */
    Rational_number &operator++();

    /**
     * @brief Overload of prefix operator --. Decrements a rational number.
     *
     * @return Rational_number&
     */
    Rational_number &operator--();

    /**
     * @brief Overload of operator +=.
     *
     * @param second Rational number to sum with
     * @return Rational_number
     */
    Rational_number operator+=(Rational_number second);

    /**
     * @brief Overload of operator -=.
     *
     * @param second Rational number to substract
     * @return Rational_number
     */
    Rational_number operator-=(Rational_number second);

    /**
     * @brief Overload of operator *=.
     *
     * @param second Rational number to multiply by
     * @return Rational_number
     */
    Rational_number operator*=(Rational_number second);

    /**
     * @brief Overload of operator /=.
     *
     * @param second Rational number to divide by
     * @return Rational_number
     */
    Rational_number operator/=(Rational_number second);

    /**
     * @brief Overload of operator +=.
     *
     * @param second Integer to sum with
     * @return Rational_number
     */
    Rational_number operator+=(int64_t second);

    /**
     * @brief Overload of operator -=.
     *
     * @param second Integer to substract
     * @return Rational_number
     */
    Rational_number operator-=(int64_t second);

    /**
     * @brief Overload of operator *=.
     *
     * @param second Integer to multiply by
     * @return Rational_number
     */
    Rational_number operator*=(int64_t second);

    /**
     * @brief Overload of operator /=.
     *
     * @param second Integer to divide by
     * @return Rational_number
     */
    Rational_number operator/=(int64_t second);

    /**
     * @brief Overload of assignment operator.
     *
     * @param second Rational number to assign.
     * @return Rational_number&
     */
    Rational_number &operator=(const Rational_number &second);

    /**
     * @brief Overload of int cast
     *
     * @return int
     */
    operator int() const;

    /**
     * @brief Overload of long int cast
     *
     * @return long int
     */
    operator long int() const;

    /**
     * @brief Overload of short cast
     *
     * @return short
     */
    operator short() const;

    /**
     * @brief Make a Rational number canonical
     *
     * @bug If both numerator and denominator are negative, they will stay
     * negative
     */
    void make_canonical();

    /**
     * @brief Make number divisible, rounding up
     *
     * @return Rational_number
     */
    Rational_number round();

    /**
     * @brief Make number divisible, rounding down
     *
     * @return Rational_number
     */
    Rational_number floor();

    /**
     * @brief Get the numerator
     *
     * @return int64_t
     */
    int64_t get_numerator() const;

    /**
     * @brief Get the denominator
     *
     * @return uint64_t
     */
    uint64_t get_denominator() const;
    friend std::ostream &operator<<(std::ostream &os,
                                    const Rational_number &rn);
};

#endif