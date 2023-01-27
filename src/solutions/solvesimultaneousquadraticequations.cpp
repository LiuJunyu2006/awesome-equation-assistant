#include <tuple>

#include "solutions/solutions.h"

using SymEngine::eval_complex_double;
using SymEngine::eval_double;
using SymEngine::I;
using SymEngine::integer;
using SymEngine::is_zero;
using SymEngine::latex;
using SymEngine::sqrt;
using SymEngine::symbol;

namespace bmp {
using namespace boost::multiprecision;
}

std::string solveSimultaneousQuadraticEquationsWithLinearEquation(const Expression& a1, const Expression& b1,
                                                                  const Expression& c1, const Expression& d1,
                                                                  const Expression& e1, const Expression& f1,
                                                                  const Expression& a2, const Expression& b2,
                                                                  const Expression& c2) {
    Expression x1, x2, y1, y2;
    if (is_zero(b2)) {
        const auto x = -c2 / a2;
        const auto ys = calculateQuadraticEquation(c1, b1 * x + e1, a1 * x * x + d1 * x + f1);
        x1 = x2 = x;
        y1 = ys.first;
        y2 = ys.second;
    } else {
        const auto p1 = -a2 / b2, q1 = -c2 / b2;
        const auto xs = calculateQuadraticEquation(a1 + b1 * p1 + c1 * p1 * p1, b1 * q1 + 2 * c1 * p1 * q1 + d1 + e1 * p1,
                                                   c1 * q1 * q1 + e1 * q1 + f1);
        x1 = xs.first;
        x2 = xs.second;
        y1 = p1 * x1 + q1;
        y2 = p1 * x2 * q1;
    }
    std::string res =
        "\\left \\{  \\begin{aligned} x_1 & = @1 & \\approx @3  \\\\ y_1 & = @2 & \\approx @4  \\end{aligned}  "
        "\\right.\\\\"
        "\\left \\{  \\begin{aligned} x_2 & = @5 & \\approx @7  \\\\ y_2 & = @6 & \\approx @8  \\end{aligned}  "
        "\\right.";
    res.replace(res.find("@1"), 2, latex(expand(x1)));
    res.replace(res.find("@2"), 2, latex(expand(y1)));
    res.replace(res.find("@5"), 2, latex(expand(x2)));
    res.replace(res.find("@6"), 2, latex(expand(y2)));
    res.replace(res.find("@3"), 2, toString(eval_complex_double(x1)));
    res.replace(res.find("@4"), 2, toString(eval_complex_double(y1)));
    res.replace(res.find("@7"), 2, toString(eval_complex_double(x2)));
    res.replace(res.find("@8"), 2, toString(eval_complex_double(y2)));
    while (res.find('j') != std::string::npos)
        res.replace(res.find('j'), 1, "\\i");
    return res;
};

Decimal toDecimal(const Expression& ex) {
    std::string s = str(ex);
    if (s.find('/') == std::string::npos)
        return Decimal(s);
    return Decimal(s.substr(0, s.find('/'))) / Decimal(s.substr(s.find('/') + 1));
}

std::string solveSimultaneousQuadraticEquations(const Expression& a1, const Expression& b1, const Expression& c1,
                                                const Expression& d1, const Expression& e1, const Expression& f1,
                                                const Expression& a2, const Expression& b2, const Expression& c2,
                                                const Expression& d2, const Expression& e2, const Expression& f2) {
    if (is_zero(a1) && is_zero(b1) && is_zero(c1) && is_zero(a2) && is_zero(b2) && is_zero(c2))
        return "\350\257\245\346\226\271\347\250\213\347\273\204\344\270\215\346\230\257\344\272\214\345\205\203\344"
               "\272\214\346\254\241\346\226\271\347\250\213\347\273\204\357\274\201";
    std::string res("\\def\\i{\\operatorname{i}}\n");
    {
        const auto x = symbol("x"), y = symbol("y");
        const auto expr1 = a1 * x * x + b1 * x * y + c1 * y * y + d1 * x + e1 * y + f1;
        res += latex(SymEngine::expand(expr1)) + "=0\\\\";
        const auto expr2 = a2 * x * x + b2 * x * y + c2 * y * y + d2 * x + e2 * y + f2;
        res += latex(SymEngine::expand(expr2)) + "=0\\\\";
    }
    if (is_zero(a1) && is_zero(b1) && is_zero(c1))
        return res + solveSimultaneousQuadraticEquationsWithLinearEquation(a2, b2, c2, d2, e2, f2, d1, e1, f1);
    if (is_zero(a2) && is_zero(b2) && is_zero(c2))
        return res + solveSimultaneousQuadraticEquationsWithLinearEquation(a1, b1, c1, d1, e1, f1, d2, e2, f2);
    using ConstExprRef = const Expression&;
    ConstExprRef a(a1), b(b1), c(c1), d(d1), e(e1), f(f1), g(a2), h(b2), i(c2), j(d2), k(e2), l(f2);
    auto p = b * b - 4 * a * c;
    auto q = 2 * b * d - 4 * a * e;
    auto r = d * d - 4 * a * f;
    auto u = g * (b * b + p) / (4 * a * a) - b * h / (2 * a) + i;
    auto v = g * (2 * b * d + q) / (4 * a * a) - (b * j + d * h) / (2 * a) + k;
    auto w = g * r / (4 * a * a) - d * j / (2 * a) + l;
    auto s = (b * g - a * h) / (2 * a * a);
    auto t = (d * g - a * j) / (2 * a * a);
    auto aa = u * u - p * s * s;
    auto bb = 2 * u * v - 2 * p * s * t - q * s * s;
    auto cc = 2 * u * w + v * v - p * t * t - 2 * q * s * t - r * s * s;
    auto dd = 2 * v * w - q * t * t - 2 * r * s * t;
    auto ee = w * w - r * t * t;
    Complex x11, x12, x21, x22, x31, x32, x41, x42, y1, y2, y3, y4;
    std::tie(y1, y2, y3, y4) =
        calculateQuarticEquation(toDecimal(aa), toDecimal(bb), toDecimal(cc), toDecimal(dd), toDecimal(ee));
    const auto function1 = [&](const Complex& yn) {
        return std::make_pair(-toDecimal(b) * yn - toDecimal(d) +
                                  bmp::sqrt(Complex(toDecimal(p) * yn * yn + toDecimal(q) * yn + toDecimal(r))),
                              -toDecimal(b) * yn - toDecimal(d) -
                                  bmp::sqrt(Complex(toDecimal(p) * yn * yn + toDecimal(q) * yn + toDecimal(r))));
    };
    std::tie(x11, x12) = function1(y1);
    std::tie(x21, x22) = function1(y2);
    std::tie(x31, x32) = function1(y3);
    std::tie(x41, x42) = function1(y4);
    const auto function2 = [](int n, const Complex& x, const Complex& y) {
        std::string str =
            "\\left \\{  \\begin{aligned} x_@1 & \\approx @2 \\\\ y_@3 & \\approx @4  \\end{aligned}  "
            "\\right.\\\\";
        str.replace(str.find("@1"), 2, std::to_string(n));
        str.replace(str.find("@3"), 2, std::to_string(n));
        str.replace(str.find("@2"), 2, toString(x));
        str.replace(str.find("@4"), 2, toString(y));
        return str;
    };
    res += function2(1, x11, y1);
    res += function2(2, x12, y1);
    res += function2(3, x21, y2);
    res += function2(4, x22, y2);
    res += function2(5, x31, y3);
    res += function2(6, x32, y3);
    res += function2(7, x41, y4);
    res += function2(8, x42, y4);
    return res;
}
