#include <exprtk.hpp>
#include <ios>
#include <string>
#include <utility>

#include "solutions/solutions.h"

const Decimal EPS = boost::multiprecision::pow(Decimal(10), -100);

Decimal calculateExpression(const std::string str) {
    exprtk::expression<Decimal> expr;
    exprtk::parser<Decimal> parser;
    parser.compile(str, expr);
    return expr.value();
}

std::pair<Decimal, Decimal> binarySearchIncrease(const std::string& expr, Decimal l, Decimal r) {
    Decimal mid;
    while (r - l > EPS) {
        std::string tmp(expr);
        mid = (l + r) / 2;
        while (tmp.find('x') != std::string::npos)
            tmp.replace(tmp.find('x'), 1, "(" + boost::multiprecision::to_string(mid) + ")");
        if (calculateExpression(tmp) < 0.0)
            l = mid;
        else
            r = mid;
    }
    return std::make_pair(l, r);
}

std::pair<Decimal, Decimal> binarySearchDecrease(const std::string& expr, Decimal l, Decimal r) {
    Decimal mid;
    while (r - l > EPS) {
        std::string tmp(expr);
        mid = (l + r) / 2;
        while (tmp.find('x') != std::string::npos)
            tmp.replace(tmp.find('x'), 1, "(" + boost::multiprecision::to_string(mid) + ")");
        if (calculateExpression(tmp) > 0.0)
            l = mid;
        else
            r = mid;
    }
    return std::make_pair(l, r);
}

std::string solveZeroPointOfMonotonicFunction(const std::string& expr, Decimal l, Decimal r, bool inc) {
    std::pair<Decimal, Decimal> res;
    if (inc)
        res = binarySearchIncrease(expr, l, r);
    else
        res = binarySearchDecrease(expr, l, r);
    return res.first.str(96, std::ios_base::fixed) + " \\leq x \\leq " + res.second.str(96, std::ios_base::fixed) +
           "\\\\ eps = " + EPS.str(96, std::ios_base::fixed);
}
