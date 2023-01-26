#include <exprtk.hpp>
#include <ios>
#include <string>
#include <utility>

#include "solutions/solutions.h"

const Decimal EPS = boost::multiprecision::pow(Decimal(2), -100);

bool xCalculateExpression(const std::string str) {
    const SymEngine::Expression expr(str);
    return SymEngine::is_positive(expr);
}

std::pair<Decimal, Decimal> xBinarySearchIncrease(const std::string& expr, Decimal l, Decimal r) {
    Decimal mid;
    while (r - l > EPS) {
        std::string tmp(expr);
        mid = (l + r) / 2;
        while (tmp.find('x') != std::string::npos)
            tmp.replace(tmp.find('x'), 1, "(" + mid.str(100, std::ios_base::fixed) + ")");
        if (xCalculateExpression(tmp))
            r = mid;
        else
            l = mid;
    }
    return std::make_pair(l, r);
}

std::pair<Decimal, Decimal> xBinarySearchDecrease(const std::string& expr, Decimal l, Decimal r) {
    Decimal mid;
    while (r - l > EPS) {
        std::string tmp(expr);
        mid = (l + r) / 2;
        while (tmp.find('x') != std::string::npos)
            tmp.replace(tmp.find('x'), 1, "(" + mid.str(100) + ")");
        if (xCalculateExpression(tmp))
            l = mid;
        else
            r = mid;
    }
    return std::make_pair(l, r);
}

std::string solveZeroPointOfMonotonicFunction(const std::string& expr, Decimal l, Decimal r, bool inc) {
    std::pair<Decimal, Decimal> res;
    if (inc)
        res = xBinarySearchIncrease(expr, l, r);
    else
        res = xBinarySearchDecrease(expr, l, r);
    return "x \\approx " + res.second.str(6, std::ios_base::fixed);
}