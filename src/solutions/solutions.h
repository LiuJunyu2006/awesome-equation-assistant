#pragma once

#include <QtCore/QString>
#include <QtCore/QVector>

#include "solutions/fraction.h"


QString solveSystemOfLinearEquations(QVector<QVector<Fraction>> a);

QString solveQuadraticEquation(const Fraction& a, const Fraction& b, const Fraction& c);

// QString solveSimultaneousQuadraticEquations(const Fraction& a1, const Fraction& b1, const Fraction& c1,
//                                             const Fraction& d1, const Fraction& e1, const Fraction& f1,
//                                             const Fraction& a2, const Fraction& b2, const Fraction& c2,
//                                             const Fraction& d2, const Fraction& e2, const Fraction& f2)

QString solveCubicEquation(const Fraction& a, const Fraction& b, const Fraction& c, const Fraction& d);

// QString solveQuarticEquation(const Fraction& a, const Fraction& b, const Fraction& c, const Fraction& d,
//                              const Fraction& e)

// QString solveLinearCongruenceEquation(const Fraction& a, const Fraction& b, const Fraction& n)

// QString solveCongruenceEquations(const QVector<QVector<Fraction>>&)

// QString solveZeroPointOfMonotonicFunction(const QString& expr, double l, double r)
