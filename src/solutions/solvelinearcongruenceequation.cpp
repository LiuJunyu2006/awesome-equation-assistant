#include "solutions.h"

BigInteger exgcd(BigInteger a, BigInteger b, BigInteger& x, BigInteger& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    BigInteger res(exgcd(b, a % b, x, y));
    const BigInteger tmp(x);
    x = y;
    y = tmp - a / b * y;
    return res;
}

std::string solveLinearCongruenceEquation(const BigInteger& a, const BigInteger& b, const BigInteger& n) {
    BigInteger x, y;
    const BigInteger d(exgcd(a, n, x, y));
    std::string res = a.str() + "x \\equiv " + b.str() + "\\pmod {" + n.str() + "}\\\\";
    if (b % d != BigInteger(0))
        return res + "\\text{\346\227\240\350\247\243\357\274\201}";
    x *= b / d;
    y *= b / d;
    BigInteger k((x - ((x - 1) % (n / d) + n / d) % (n / d) - 1) / (n / d));
    x = ((x - 1) % (n / d) + n / d) % (n / d) + 1;
    res += "x \\equiv " + x.str() + "\\pmod {" + n.str() + "}";
    return res;
}
