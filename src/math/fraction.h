#ifndef MATH_FRACTION_H
#define MATH_FRACTION_H

#include <boost/multiprecision/cpp_int.hpp>

using BigInteger = boost::multiprecision::cpp_int;
using boost::multiprecision::gcd;

class Fraction {
  public:
    Fraction(const BigInteger& x, const BigInteger& y) : num(x), den(y) {
        maintain();
    }

    Fraction operator+(const Fraction& oth) {
        return Fraction(num * oth.den + oth.num * den, den * oth.den);
    }

    Fraction operator-(const Fraction& oth) {
        return Fraction(num * oth.den - oth.num * den, den * oth.den);
    }

    Fraction operator*(const Fraction& oth) {
        return Fraction(num * oth.num, den * oth.den);
    }

    Fraction operator/(const Fraction& oth) {
        return Fraction(num * oth.den, den * oth.num);
    }

  private:
    BigInteger num, den;

    void maintain() {
        BigInteger g = gcd(num, den);
        num /= g;
        den /= g;
    }
};

#endif  // MATH_FRACTION_H
