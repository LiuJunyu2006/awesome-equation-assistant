#include "solutions/solutions.h"

using SymEngine::eval_complex_double;
using SymEngine::eval_double;
using SymEngine::I;
using SymEngine::integer;
using SymEngine::is_positive;
using SymEngine::is_zero;
using SymEngine::latex;
using SymEngine::sqrt;
using SymEngine::symbol;

template <>
std::string toString(const std::complex<double>& val) {
    std::string res;
    bool flag = false;
    if (val.real() != 0.0) {
        flag = true;
        res += std::to_string(val.real());
    }
    if (val.imag() != 0.0) {
        if (flag && val.imag() >= 0.0)
            res += "+";
        res += std::to_string(val.imag()) + "\\i";
    }
    return res;
}

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
    const auto x = symbol("x");
    std::string res("\\def\\i{\\operatorname{i}}\n");
    const auto expr = a * pow(x, integer(2)) + b * x + c;
    res += latex(SymEngine::expand(expr)) + "=0\\\\";
    const auto delta = b * b - 4 * a * c;
    res += "\\Delta=b^2-4ac=" + latex(delta) + "\\\\";
    if (is_zero(delta)) {
        res += "x_1=x_2=-\\frac{b}{2a}=" + latex(expand(-b / (2 * a))) + "\\approx" +
               std::to_string(eval_double((-b / (2 * a))));
    } else if (is_positive(delta)) {
        const auto x1 = expand(-b + sqrt(delta)) / (2 * a);
        const auto x2 = expand(-b - sqrt(delta)) / (2 * a);
        res += "x_1=\\frac{-b+\\sqrt{\\Delta}}{2a}=" + latex(x1) + "\\approx" + std::to_string(eval_double(x1)) +
               "\\\\" + "x_2=\\frac{-b-\\sqrt{\\Delta}}{2a}=" + latex(x2) + "\\approx" +
               std::to_string(eval_double(x2));
    } else {
        const auto x1 = expand(-b + sqrt(-delta) * Expression(I)) / (2 * a);
        const auto x2 = expand(-b - sqrt(-delta) * Expression(I)) / (2 * a);
        res += "x_1=\\frac{-b+\\operatorname{i}\\sqrt{-\\Delta}}{2a}=" + latex(x1) + "\\approx" +
               toString(eval_complex_double(x1)) + "\\\\" +
               "x_2=\\frac{-b-\\operatorname{i}\\sqrt{-\\Delta}}{2a}=" + latex(x2) + "\\approx" +
               toString(eval_complex_double(x2));
        while (res.find('j') != std::string::npos)
            res.replace(res.find('j'), 1, "\\operatorname{i}");
    }
    return res;
}

std::pair<Expression, Expression> calculateQuadraticEquation(const Expression& a, const Expression& b,
                                                             const Expression& c) {
    const auto delta = b * b - 4 * a * c;
    if (is_zero(delta))
        return {-b / (2 * a), -b / (2 * a)};
    if (is_positive(delta)) {
        const auto x1 = (-b + sqrt(delta)) / (2 * a);
        const auto x2 = (-b - sqrt(delta)) / (2 * a);
        return {x1, x2};
    }
    const auto x1 = (-b + sqrt(-delta) * Expression(I)) / (2 * a);
    const auto x2 = (-b - sqrt(-delta) * Expression(I)) / (2 * a);
    return {expand(x1), expand(x2)};
}
