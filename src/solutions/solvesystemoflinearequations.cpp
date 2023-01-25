#include <utility>

#include "solutions/solutions.h"

// QString solveSystemOfLinearEquations(QVector<QVector<Fraction>> a) {
//     int n = a.size(), m = a.front().size();
//     for (int i = 1; i <= n; ++i) {
//         for (int j = i; j <= n; ++j)
//             if (!a[j - 1][i - 1].isZero()) {
//                 if (j > i)
//                     std::swap(a[j - 1], a[i - 1]);
//                 break;
//             }
//         if (a[i - 1][i - 1].isZero())
//             return QString::fromUtf8(
//                 "\346\255\244\346\226\271\347\250\213\346\227\240\350\247\243\346\210\226\346\234\211\346\227\240\346"
//                 "\225\260\344\270\252\350\247\243\357\274\201");
//         for (int j = n + 1; j >= i; --j)
//             a[i - 1][j - 1] = a[i - 1][j - 1] / a[i - 1][i - 1];
//         for (int j = 1; j <= n; ++j) {
//             if (j == i || a[j - 1][i - 1].isZero())
//                 continue;
//             auto w = a[j - 1][i - 1];
//             for (int k = 1; k <= n + 1; ++k)
//                 a[j - 1][k - 1] = a[j - 1][k - 1] - a[i - 1][k - 1] * w;
//         }
//     }
//     QString res;
//     for (int i = 0; i < m - 1; ++i)
//         res += QString("x_%1=").arg(i + 1) + a[i][m - 1].toKaTex() + "\\\\";
//     return res;
// }

std::string toLatex(const Rational& x) {
    if (x.denominator() == BigInteger(1))
        return x.numerator().str();
    else
        return "\\frac{" + x.numerator().str() + "}{" + x.denominator().str() + "}";
}

std::string solveSystemOfLinearEquations(int equations, int unknowns, std::vector<std::vector<Rational>> vec) {
    if (equations < unknowns)
        return "\\text{"
               "\350\257\245\346\226\271\347\250\213\346\227\240\350\247\243\346\210\226\344\270\215\345\255\230\345"
               "\234\250\345\224\257\344\270\200\350\247\243\357\274\201}";
    for (int i = 0; i < unknowns; ++i) {
        for (int j = i; j < equations; ++j) {
            if (vec[j][i] != Rational(0))
                std::swap(vec[j], vec[i]);
            break;
        }
        if (vec[i][i] == Rational(0))
            return "\\text{"
                   "\350\257\245\346\226\271\347\250\213\346\227\240\350\247\243\346\210\226\344\270\215\345\255\230"
                   "\345\234\250\345\224\257\344\270\200\350\247\243\357\274\201}";
        for (int j = unknowns; j >= i; --j)
            vec[i][j] /= vec[i][i];
        for (int j = 0; j < equations; ++j) {
            if (j == i || vec[j][i] == Rational(0))
                continue;
            auto w = vec[j][i];
            for (int k = 0; k <= unknowns; ++k)
                vec[j][k] -= vec[i][k] * w;
        }
    }
    for (int i = unknowns; i < equations; ++i)
        if (vec[i][unknowns] != Rational(0))
            return "\\text{\346\227\240\350\247\243\357\274\201}";
    std::string res;
    for (int i = 0; i < unknowns; ++i)
        res += "x_" + std::to_string(i + 1) + "=" + toLatex(vec[i][unknowns]) + "\\\\";
    return res;
}