#include "solutions/solutions.h"

using SymEngine::I;
using SymEngine::integer;
using SymEngine::latex;
using SymEngine::sqrt;
using SymEngine::symbol;

std::string solveQuadraticEquation(const Expression& a, const Expression& b, const Expression& c) {
    //    return R"(x^2+x-1=0\\
\Delta=b^2-4ac=5>0\\
x_1=\dfrac{-b+\sqrt{b^2-4ac}}{2a}=-\dfrac{1}{2}+\dfrac{\sqrt{5}}{2}\\
x_2=\dfrac{-b-\sqrt{b^2-4ac}}{2a}=-\dfrac{1}{2}-\dfrac{\sqrt{5}}{2})";
    if (is_zero(a))
        return "\\text{"
               "\350\277\231\344\270\215\346\230\257\344\270\200\344\270\252\344\270\200\345\205\203\344\272\214\346"
               "\254"
               "\241\346\226\271\347\250\213\357\274\201}";

    // auto res = QString("%1x^2").arg(a.toKaTexAsCoefficient()) +
    // (!b.isZero() ? QString("%1x").arg(b.toKaTexAsCoefficientWithPositiveSign()) : QString()) +
    //    (!c.isZero() ? c.toKaTexWithPositiveSign() : QString()) + QString("=0\\\\");

    // Fraction delta = b * b - Fraction("4") * a * c;
    //  int comp = delta.isZero() ? 0 : (delta > Fraction("0") ? 1 : -1);
    //  res += QString("\\Delta=b^2-4ac=%1").arg(delta.toKaTex());
    //  if (comp == 1)
    //      res += ">0";
    //  else if (comp == -1)
    //      res += "<0";
    //  res += "\\\\";
    auto x = symbol("x");
    std::string res;
    auto expr = a * pow(x, integer(2)) + b * x + c;
    res += latex(SymEngine::expand(expr)) + "=0\\\\";
    auto delta = b * b - 4 * a * c;
    res += "\\Delta=b^2-4ac=" + latex(delta) + "\\\\";
    if (is_zero(delta)) {
        res += "x_1=x_2=-\\frac{b}{2a}=" + latex(-b / (2 * a));
    } else if (is_positive(delta)) {
        auto x1 = (-b + sqrt(delta)) / (2 * a);
        auto x2 = (-b - sqrt(delta)) / (2 * a);
        res += "x_1=\\frac{-b+\\sqrt{\\Delta}}{2a}=" + latex(x1) + "\\\\" +
               "x_2=\\frac{-b-\\sqrt{\\Delta}}{2a}=" + latex(x2);
    } else {
        auto x1 = (-b + sqrt(-delta) * Expression(I)) / (2 * a);
        auto x2 = (-b - sqrt(-delta) * Expression(I)) / (2 * a);
        res += "x_1=\\frac{-b+\\operatorname{i}\\sqrt{-\\Delta}}{2a}=" + latex(x1) + "\\\\" +
               "x_2=\\frac{-b-\\operatorname{i}\\sqrt{-\\Delta}}{2a}=" + latex(x2);
        while (res.find('j') != std::string::npos)
            res.replace(res.find('j'), 1, "\\operatorname{i}");
    }
    return res;
}
