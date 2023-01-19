#include "solutions/solutions.h"

using SymEngine::integer;
using SymEngine::latex;
using SymEngine::symbol;

using boost::multiprecision::to_string;

std::string solveCubicEquation(const Decimal& a, const Decimal& b, const Decimal& c, const Decimal& d) {
    if (a == Decimal(0))
        return "\\text{"
               "\350\257\245\346\226\271\347\250\213\344\270\215\346\230\257\344\270\200\345\205\203\344\270\211\346"
               "\254\241\346\226\271\347\250\213\357\274\201}";
    auto x = symbol("x");
    std::string res;
    auto expr = Expression(to_string(a)) * pow(x, integer(3)) + Expression(to_string(b)) * pow(x, integer(2)) +
                Expression(to_string(c)) * x + Expression(to_string(d));
    res += latex(expr) + "=0\\\\\n";
    res +=
        "\\def\\i{\\operatorname{i}}\n\\def\\apple{\\sqrt{\\left(\\frac{bc}{6a^2}-\\frac{b^3}{27a^3}-\\frac{d}{2a}"
        "\\right)^2+\\left(\\frac{c}{3a}-\\frac{b^2}{9a^2}\\right)^3}}\n\\def\\banana{\\sqrt[3]{\\frac{bc}{6a^2}-"
        "\\frac{b^3}]{\\frac{bc}{6a^2}-\\frac{b^3}{27a^3}-\\frac{d}{2a}-\\{27a^3}-\\frac{d}{2a}+\\apple}}"
        "\n\\def\\cherry{\\sqrt[3apple}}\n\\def\\grape{\\frac{-1+\\i\\sqrt{3}}{2}}\n\\def\\orange{\\frac{-1-\\i\\sqrt{"
        "3}}{2}}\n\\def\\pear{\\frac{b}{3a}}\nx_1=-\\pear+\\banana+\\cherry\\\\x_2=-\\pear+\\grape\\banana+"
        "\\orange\\cherry\\\\x_3=-\\pear+\\orange\\banana+\\grape\\cherry";
    return res;
}