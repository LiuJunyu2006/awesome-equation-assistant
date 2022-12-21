#include "solutions/fraction.h"
#include "solutions/solutions.h"

QString solveQuadraticEquation(const Fraction& a, const Fraction& b, const Fraction& c) {
    //    return R"(x^2+x-1=0\\
\Delta=b^2-4ac=5>0\\
x_1=\dfrac{-b+\sqrt{b^2-4ac}}{2a}=-\dfrac{1}{2}+\dfrac{\sqrt{5}}{2}\\
x_2=\dfrac{-b-\sqrt{b^2-4ac}}{2a}=-\dfrac{1}{2}-\dfrac{\sqrt{5}}{2})";
    if (a.isZero())
        return QString::fromUtf8(
            "\\text{"
            "\350\277\231\344\270\215\346\230\257\344\270\200\344\270\252\344\270\200\345\205\203\344\272\214\346\254"
            "\241\346\226\271\347\250\213\357\274\201}");

    auto res = QString("%1x^2").arg(a.toKaTexAsCoefficient()) +
               (!b.isZero() ? QString("%1x").arg(b.toKaTexAsCoefficientWithPositiveSign()) : QString()) +
               (!c.isZero() ? c.toKaTexWithPositiveSign() : QString()) + QString("=0\\\\");

    Fraction delta = b * b - Fraction("4") * a * c;
    int comp = delta.isZero() ? 0 : (delta > Fraction("0") ? 1 : -1);
    res += QString("\\Delta=b^2-4ac=%1").arg(delta.toKaTex());
    if (comp == 1)
        res += ">0";
    else if (comp == -1)
        res += "<0";
    res += "\\\\";

    return res;
}
