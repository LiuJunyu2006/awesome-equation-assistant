#include <boost/multiprecision/cpp_complex.hpp>

#include "solutions/solutions.h"

using SymEngine::integer;
using SymEngine::latex;
using SymEngine::symbol;
;

namespace bmp {
using namespace boost::multiprecision;
}

std::string solveCubicEquation(const Decimal& a, const Decimal& b, const Decimal& c, const Decimal& d) {
    if (a == Decimal(0))
        return "\\text{"
               "\350\257\245\346\226\271\347\250\213\344\270\215\346\230\257\344\270\200\345\205\203\344\270\211\346"
               "\254\241\346\226\271\347\250\213\357\274\201}";
    auto x = symbol("x");
    std::string res;
    auto expr = Expression(a.str(100)) * pow(x, integer(3)) + Expression(b.str()) * pow(x, integer(2)) +
                Expression(c.str(100)) * x + Expression(d.str(100));
    res += latex(expr) + "=0\\\\\n";
    res += "\\def\\i{\\operatorname{i}}\n";
    Complex i(Decimal(0), Decimal(1));
    res +=
        "\\def\\apple{\\sqrt{\\left(\\frac{bc}{6a^2}-\\frac{b^3}{27a^3}-\\frac{d}{2a}\\right)^2+\\left(\\frac{c}{3a}-"
        "\\frac{b^2}{9a^2}\\right)^3}}\n";
    auto apple = bmp::sqrt(
        Complex(square(b * c / Decimal(6) / square(a) - cube(b) / Decimal(27) / cube(a) - d / Decimal(2) / a) +
                cube(c / Decimal(3) / a - square(b) / Decimal(9) / square(a))));
    res += "\\def\\banana{\\sqrt[3]{\\frac{bc}{6a^2}-\\frac{b^3}{27a^3}-\\frac{d}{2a}+\\apple}}\n";
    auto banana =
        bmp::pow(b * c / Decimal(6) / square(a) - cube(b) / Decimal(27) / cube(a) - d / Decimal(2) / a + apple,
                 Decimal(1) / Decimal(3));
    res += "\\def\\cherry{\\sqrt[3]{\\frac{bc}{6a^2}-\\frac{b^3}{27a^3}-\\frac{d}{2a}-\\apple}}\n";
    auto cherry =
        bmp::pow(b * c / Decimal(6) / square(a) - cube(b) / Decimal(27) / cube(a) - d / Decimal(2) / a - apple,
                 Decimal(1) / Decimal(3));
    res += "\\def\\grape{\\frac{-1+\\i\\sqrt{3}}{2}}\n";
    auto grape = (-Decimal(1) + bmp::sqrt(Decimal(3)) * i) / Decimal(2);
    res += "\\def\\orange{\\frac{-1-\\i\\sqrt{3}}{2}}\n";
    auto orange = (-Decimal(1) - bmp::sqrt(Decimal(3)) * i) / Decimal(2);
    res += "\\def\\pear{\\frac{b}{3a}}\n";
    auto pear = b / Decimal(3) / a;
    Complex x1(-pear + banana + cherry);
    res += "x_1=-\\pear+\\banana+\\cherry\\approx" + toString(x1) + "\\\\\n";
    Complex x2(-pear + grape * banana + orange * cherry);
    res += "x_2=-\\pear+\\grape\\banana+\\orange\\cherry\\approx" + toString(x2) + "\\\\\n";
    Complex x3(-pear + orange * banana + grape * cherry);
    res += "x_3=-\\pear+\\orange\\banana+\\grape\\cherry\\approx" + toString(x3);
    return res;
}