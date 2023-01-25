#include <boost/optional/optional.hpp>

#include "solutions/solutions.h"

using OptionalPairBigInteger = boost::optional<std::pair<BigInteger, BigInteger>>;

OptionalPairBigInteger calculateCongruenceEquations(int n, const std::vector<std::pair<BigInteger, BigInteger>>& vec) {
    BigInteger r = (vec[0].first + vec[0].second) % vec[0].second;
    BigInteger m = vec[0].second;
    if (n == 1)
        return OptionalPairBigInteger(std::make_pair(r, m));
    for (int i = 1; i < n; ++i) {
        auto g = boost::multiprecision::gcd(m, vec[i].second);
        auto c = vec[i].first - r;
        if (c % g != BigInteger(0))
            return boost::none;
        BigInteger k1, k2;
        exgcd(m / g, vec[i].second / g, k1, k2);
        auto x = (c / g * k1) % (vec[i].second / g);
        r += x * m;
        m = m * vec[i].second / g;
        r = (r + m) % m;
    }
    return OptionalPairBigInteger(std::make_pair(r, m));
}

std::string solveCongruenceEquations(int n, const std::vector<std::pair<BigInteger, BigInteger>>& vec) {
    auto res = calculateCongruenceEquations(n, vec);
    if (res.has_value())
        return "x \\equiv " + res.value().first.str() + "\\pmod {" + res.value().second.str() + "}\\\\";
    else
        return "\\text{\346\227\240\350\247\243\357\274\201}";
}