#include <algorithm>
#include <ios>
#include <tuple>
#include <vector>

#include "solutions.h"

using SymEngine::integer;
using SymEngine::latex;
using SymEngine::symbol;

namespace bmp {
using namespace boost::multiprecision;
}

std::string solveQuarticEquation(const Decimal& a, const Decimal& b, const Decimal& c, const Decimal& d,
                                 const Decimal& e) {
    if (a.is_zero())
        return "\350\277\231\344\270\215\346\230\257\344\270\200\344\270\252\344\270\200\345\205\203\345\233\233\346"
               "\254\241\346\226\271\347\250\213\357\274\201";
    auto x = symbol("x");
    std::string res = "\\def\\i{\\operatorname{i}}\n";
    auto expr = Expression(a.str(100)) * pow(x, integer(4)) + Expression(b.str()) * pow(x, integer(3)) +
                Expression(c.str(100)) * pow(x, integer(2)) + Expression(d.str(100)) * x + Expression(e.str(100));
    res += latex(expr) + "=0\\\\\n";
    res += "a \\approx" + a.str(6, std::ios::fixed) + "\\\\";
    res += "b \\approx" + b.str(6, std::ios::fixed) + "\\\\";
    res += "c \\approx" + c.str(6, std::ios::fixed) + "\\\\";
    res += "d \\approx" + d.str(6, std::ios::fixed) + "\\\\";
    res += "e \\approx" + e.str(6, std::ios::fixed) + "\\\\";
    
    Complex x1, x2, x3, x4;
    std::tie(x1, x2, x3, x4) = calculateQuarticEquation(a, b, c, d, e);
    // Complex x1 = (-b + tmp1 + bmp::sqrt(tmp2 - 2 * rho)) / (4 * a);
    res += "x_1\\approx" + toString(x1) + "\\\\";
    // Complex x2 = (-b + tmp1 - bmp::sqrt(tmp2 - 2 * rho)) / (4 * a);
    res += "x_2\\approx" + toString(x2) + "\\\\";
    // Complex x3 = (-b - tmp1 + bmp::sqrt(tmp2 + 2 * rho)) / (4 * a);
    res += "x_3\\approx" + toString(x3) + "\\\\";
    // Complex x4 = (-b - tmp1 - bmp::sqrt(tmp2 + 2 * rho)) / (4 * a);
    res += "x_4\\approx" + toString(x4) + "\\\\";
    return res;
}

std::tuple<Complex, Complex, Complex, Complex> calculateQuarticEquation(const Decimal& a, const Decimal& b,
                                                                        const Decimal& c, const Decimal& d,
                                                                        const Decimal& e) {
    /*auto delta1 = c * c - 3 * b * d + 12 * a * e;
    auto delta2 = 2 * c * c * c - 9 * b * c * d + 27 * a * d * d + 27 * b * b * e - 72 * a * c * e;
    const auto cbrt2 = bmp::cbrt(Decimal(2));
    auto onethird = Decimal(1) / Decimal(3);
    auto delta =
        cbrt2 * delta1 /
            (3 * a * bmp::pow(delta2 + bmp::sqrt(Complex(-4 * delta1 * delta1 * delta1 + delta2 * delta2)), onethird)) +
        pow(delta2 + bmp::sqrt(Complex(-4 * delta1 * delta1 * delta1 + delta2 * delta2)), onethird) / (3 * cbrt2 * a);
    auto x1 =
        -b / (4 * a) - bmp::sqrt(Complex(b * b / (4 * a * a) - 2 * c / (3 * a) + delta)) / 2 -
    bmp::sqrt(Complex(b*b/(2*a*a)-4*c/(3*a)-delta-(-b*b*b/(a*a*a)+4*b*c/(a*a)-8*d/a)/(4*bmp::sqrt(Complex(b*b/(4*a*a)-2*c/(3*a)+delta)))))/2;
    auto x2 =
        -b / (4 * a) - bmp::sqrt(Complex(b * b / (4 * a * a) - 2 * c / (3 * a) + delta)) / 2 +
    bmp::sqrt(Complex(b*b/(2*a*a)-4*c/(3*a)-delta-(-b*b*b/(a*a*a)+4*b*c/(a*a)-8*d/a)/(4*bmp::sqrt(Complex(b*b/(4*a*a)-2*c/(3*a)+delta)))))/2;
    auto x3 =
        -b / (4 * a) + bmp::sqrt(Complex(b * b / (4 * a * a) - 2 * c / (3 * a) + delta)) / 2 -
    bmp::sqrt(Complex(b*b/(2*a*a)-4*c/(3*a)-delta+(-b*b*b/(a*a*a)+4*b*c/(a*a)-8*d/a)/(4*bmp::sqrt(Complex(b*b/(4*a*a)-2*c/(3*a)+delta)))))/2;
    auto x4 =
        -b / (4 * a) + bmp::sqrt(Complex(b * b / (4 * a * a) - 2 * c / (3 * a) + delta)) / 2 +
    bmp::sqrt(Complex(b*b/(2*a*a)-4*c/(3*a)-delta+(-b*b*b/(a*a*a)+4*b*c/(a*a)-8*d/a)/(4*bmp::sqrt(Complex(b*b/(4*a*a)-2*c/(3*a)+delta)))))/2;
    std::string logg;
    logg += "delta1=" + delta1.str() + "\n";
    logg += "delta2=" + delta2.str() + "\n";
    logg += "delta=" + delta.str() + "\n";
    logg += "x1=" + x1.str() + "\n";
    logg += "x2=" + x2.str() + "\n";
    logg += "x3=" + x3.str() + "\n";
    logg += "x4=" + x4.str() + "\n";*/
    const auto onethird = Decimal(1) / Decimal(3);
    auto p = (c * c + 12 * e - 3 * b * d) / 9;
    auto q = (27 * d * d + 2 * c * c * c + 27 * b * b * e - 72 * c * e - 9 * b * c * d) / 54;
    auto de = bmp::sqrt(Complex(q * q - p * p * p));
    auto u = (bmp::abs(bmp::pow(q + de, onethird)) >= bmp::abs(bmp::pow(q - de, onethird)))
                 ? bmp::pow(q + de, onethird)
                 : bmp::pow(q - de, onethird);
    auto v = (u.is_zero()) ? 0 : p / u;
    const auto omiga = (-1 + bmp::sqrt(Decimal(3)) * Complex(0, 1)) / 2;
    const auto omiga2 = (-1 - bmp::sqrt(Decimal(3)) * Complex(0, 1)) / 2;
    auto y1 = u + v + c / 3;
    auto y2 = omiga * u + omiga2 * v + c / 3;
    auto y3 = omiga2 * u + omiga * v + c / 3;
    const auto function1 = [&](const auto& yn) { return bmp::sqrt(Complex(b * b + 4 * yn - 4 * c)); };
    const auto cmp1 = [&](const auto& c1, const auto& c2) { return bmp::abs(c1) > bmp::abs(c2); };
    auto y = y1, m = function1(y1);
    if (cmp1(function1(y2), m))
        y = y2, m = function1(y2);
    if (cmp1(function1(y3), m))
        y = y3, m = function1(y3);
    Complex x1, x2, x3, x4;
    if (m.is_zero()) {
        x1 = x2 = (-b + bmp::sqrt(Complex(b * b - 8 * y))) / 4;
        x3 = x4 = (-b - bmp::sqrt(Complex(b * b - 8 * y))) / 4;
    } else {
        auto n = (b * y - 2 * d) / m;
        x1 = (-(b + m) + bmp::sqrt(Complex((b + m) * (b + m) - 8 * (y + n)))) / 4;
        x2 = (-(b + m) - bmp::sqrt(Complex((b + m) * (b + m) - 8 * (y + n)))) / 4;
        x3 = (-(b - m) + bmp::sqrt(Complex((b - m) * (b - m) - 8 * (y - n)))) / 4;
        x4 = (-(b - m) - bmp::sqrt(Complex((b - m) * (b - m) - 8 * (y - n)))) / 4;
    }
    return std::make_tuple(x1, x2, x3, x4);
}
