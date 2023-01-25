#pragma once

#include <symengine/expression.h>

#include <boost/multiprecision/cpp_complex.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/optional/optional.hpp>
#include <boost/rational.hpp>
#include <complex>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using SymEngine::Expression;
using Complex = boost::multiprecision::cpp_complex_100;
using Decimal = Complex::value_type;
using BigInteger = boost::multiprecision::cpp_int;
using Rational = boost::rational<BigInteger>;

std::string solveSystemOfLinearEquations(int equations, int unknowns, std::vector<std::vector<Rational>> vec);

std::string solveQuadraticEquation(const Expression& a, const Expression& b, const Expression& c);

std::string solveSimultaneousQuadraticEquations(const Expression& a1, const Expression& b1, const Expression& c1,
                                                const Expression& d1, const Expression& e1, const Expression& f1,
                                                const Expression& a2, const Expression& b2, const Expression& c2,
                                                const Expression& d2, const Expression& e2, const Expression& f2);

std::string solveCubicEquation(const Decimal& a, const Decimal& b, const Decimal& c, const Decimal& d);

std::string solveQuarticEquation(const Decimal& a, const Decimal& b, const Decimal& c, const Decimal& d,
                                 const Decimal& e);

std::string solveLinearCongruenceEquation(const BigInteger& a, const BigInteger& b, const BigInteger& n);

std::string solveCongruenceEquations(int n, const std::vector<std::pair<BigInteger, BigInteger>>& vec);

std::string solveZeroPointOfMonotonicFunction(const std::string& expr, Decimal l, Decimal r, bool inc);

template <typename T>
inline T square(const T& val) {
    return val * val;
}

template <typename T>
inline T cube(const T& val) {
    return val * val * val;
}

template <typename C>
std::string toString(const C& val) {
    std::string res;
    bool flag = false;
    if (val.real().str(6, std::ios_base::fixed) != "0.000000") {
        flag = true;
        res += val.real().str(6, std::ios_base::fixed);
    }
    if (val.imag().str(6, std::ios_base::fixed) != "0.000000") {
        if (flag && val.imag().str(6, std::ios_base::fixed).front() != '-')
            res += "+";
        res += val.imag().str(6, std::ios_base::fixed) + "\\i";
    }
    return res;
}

template <>
std::string toString(const std::complex<double>& val);

BigInteger exgcd(BigInteger a, BigInteger b, BigInteger& x, BigInteger& y);

boost::optional<std::tuple<Decimal, Decimal, Decimal>> calculateCubicEquation(const Decimal& a, const Decimal& b,
                                                                              const Decimal& c, const Decimal& d);