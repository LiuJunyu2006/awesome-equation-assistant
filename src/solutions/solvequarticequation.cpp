#include "solutions.h"

using SymEngine::integer;
using SymEngine::latex;
using SymEngine::symbol;

std::string solveQuarticEquation(const Decimal& a, const Decimal& b, const Decimal& c, const Decimal& d,
                                 const Decimal& e) {
    if (a.is_zero())
        return "\350\277\231\344\270\215\346\230\257\344\270\200\344\270\252\344\270\200\345\205\203\345\233\233\346"
               "\254\241\346\226\271\347\250\213\357\274\201";
    auto x = symbol("x");
    std::string res;
    auto expr = Expression(a.str(100)) * pow(x, integer(4)) + Expression(b.str()) * pow(x, integer(3)) +
                Expression(c.str(100)) * pow(x, integer(2)) + Expression(d.str(100)) * x + Expression(e.str(100));
    res += latex(expr) + "=0\\\\\n";
    auto delta = b * b * b - Decimal(4) * a * b * c + Decimal(4) * a * a * d;
    res += "\\Delta=b^3-4abc+8a^2d";
    return res;
}
