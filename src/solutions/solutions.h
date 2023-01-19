#pragma once

#include <symengine/expression.h>

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <string>
#include <vector>

using Decimal = boost::multiprecision::cpp_dec_float_100;

using SymEngine::Expression;

// QString solveSystemOfLinearEquations(QVector<QVector<Fraction>> a);

std::string solveQuadraticEquation(const Expression& a, const Expression& b, const Expression& c);

// QString solveSimultaneousQuadraticEquations(const Fraction& a1, const Fraction& b1, const Fraction& c1,
//                                             const Fraction& d1, const Fraction& e1, const Fraction& f1,
//                                             const Fraction& a2, const Fraction& b2, const Fraction& c2,
//                                             const Fraction& d2, const Fraction& e2, const Fraction& f2)

std::string solveCubicEquation(const Decimal& a, const Decimal& b, const Decimal& c, const Decimal& d);

// QString solveQuarticEquation(const Fraction& a, const Fraction& b, const Fraction& c, const Fraction& d,
//                              const Fraction& e)

// QString solveLinearCongruenceEquation(const Fraction& a, const Fraction& b, const Fraction& n)

// QString solveCongruenceEquations(const QVector<QVector<Fraction>>&)

std::string solveZeroPointOfMonotonicFunction(const std::string& expr, Decimal l, Decimal r, bool inc);
