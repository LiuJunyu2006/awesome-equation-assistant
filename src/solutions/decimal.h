/*
 **************************************************************
 *         C++ Mathematical Expression Toolkit Library        *
 *                                                            *
 * Custom Real type Adaptor                                   *
 * Authors: Arash Partow                                      *
 * URL: http://www.partow.net/programming/exprtk/index.html   *
 *                                                            *
 * Copyright notice:                                          *
 * Free use of the Mathematical Expression Toolkit Library is *
 * permitted under the guidelines and in accordance with the  *
 * most current version of the MIT License.                   *
 * http://www.opensource.org/licenses/MIT                     *
 *                                                            *
 **************************************************************
 */

#pragma once

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <string>

using Decimal = boost::multiprecision::cpp_dec_float_100;

#include <algorithm>
#include <cmath>
#include <limits>
#include <string>

namespace real {
struct type {
    type() : d_(0) {}

    type(const type& d) : d_(d.d_) {}

    template <typename T>
    explicit type(const T& d) : d_(d) {}
    
    template <typename T>
    type& operator=(const T d) {
        d_ = d;
        return *this;
    }

    inline type& operator+=(const type& r) {
        d_ += r.d_;
        return *this;
    }
    inline type& operator-=(const type& r) {
        d_ -= r.d_;
        return *this;
    }
    inline type& operator*=(const type& r) {
        d_ *= r.d_;
        return *this;
    }
    inline type& operator/=(const type& r) {
        d_ /= r.d_;
        return *this;
    }

    inline type& operator=(const double r) {
        d_ = r;
        return *this;
    }
    inline type& operator+=(const double r) {
        d_ += r;
        return *this;
    }
    inline type& operator-=(const double r) {
        d_ -= r;
        return *this;
    }
    inline type& operator*=(const double r) {
        d_ *= r;
        return *this;
    }
    inline type& operator/=(const double r) {
        d_ /= r;
        return *this;
    }

    inline type& operator++() {
        d_ += 1.0;
        return *this;
    }
    inline type& operator--() {
        d_ -= 1.0;
        return *this;
    }

    inline type operator++(int) {
        type tmp(d_);
        d_ += 1.0;
        return tmp;
    }
    inline type operator--(int) {
        type tmp(d_);
        d_ -= 1.0;
        return tmp;
    }

    inline type operator-() const {
        type d;
        d.d_ = -d_;
        return d;
    }

    template <typename T>
    inline operator T() const {
        return static_cast<T>(d_);
    }
    inline operator bool() const {
        return (d_ != 0.0);
    }

    inline bool operator==(const type& r) const {
        return (d_ == r.d_);
    }
    inline bool operator!=(const type& r) const {
        return (d_ != r.d_);
    }

    boost::multiprecision::cpp_dec_float_100 d_;
};

inline type operator+(const type r0, const type r1) {
    return type(r0.d_ + r1.d_);
}
inline type operator-(const type r0, const type r1) {
    return type(r0.d_ - r1.d_);
}
inline type operator*(const type r0, const type r1) {
    return type(r0.d_ * r1.d_);
}
inline type operator/(const type r0, const type r1) {
    return type(r0.d_ / r1.d_);
}

inline bool operator<(const type r0, const type r1) {
    return (r0.d_ < r1.d_);
}
inline bool operator>(const type r0, const type r1) {
    return (r0.d_ > r1.d_);
}
inline bool operator<=(const type r0, const type r1) {
    return (r0.d_ <= r1.d_);
}
inline bool operator>=(const type r0, const type r1) {
    return (r0.d_ >= r1.d_);
}

#define real_define_inequalities(Type)                                                           \
    inline type operator+(const Type /*&*/ r0, const type /*&*/ r1) { return type(r0 + r1.d_); } \
    inline type operator-(const Type /*&*/ r0, const type /*&*/ r1) { return type(r0 - r1.d_); } \
    inline type operator*(const Type /*&*/ r0, const type /*&*/ r1) { return type(r0 * r1.d_); } \
    inline type operator/(const Type /*&*/ r0, const type /*&*/ r1) { return type(r0 / r1.d_); } \
    inline bool operator<(const Type /*&*/ r0, const type /*&*/ r1) { return (r0 < r1.d_); }     \
    inline bool operator>(const Type /*&*/ r0, const type /*&*/ r1) { return (r0 > r1.d_); }     \
    inline bool operator<=(const Type /*&*/ r0, const type /*&*/ r1) { return (r0 <= r1.d_); }   \
    inline bool operator>=(const Type /*&*/ r0, const type /*&*/ r1) { return (r0 >= r1.d_); }   \
    inline bool operator==(const Type /*&*/ r0, const type /*&*/ r1) { return (r0 == r1.d_); }   \
    inline bool operator!=(const Type /*&*/ r0, const type /*&*/ r1) { return (r0 != r1.d_); }   \
    inline type operator+(const type /*&*/ r0, const Type /*&*/ r1) { return type(r0.d_ + r1); } \
    inline type operator-(const type /*&*/ r0, const Type /*&*/ r1) { return type(r0.d_ - r1); } \
    inline type operator*(const type /*&*/ r0, const Type /*&*/ r1) { return type(r0.d_ * r1); } \
    inline type operator/(const type /*&*/ r0, const Type /*&*/ r1) { return type(r0.d_ / r1); } \
    inline bool operator<(const type /*&*/ r0, const Type /*&*/ r1) { return (r0.d_ < r1); }     \
    inline bool operator>(const type /*&*/ r0, const Type /*&*/ r1) { return (r0.d_ > r1); }     \
    inline bool operator<=(const type /*&*/ r0, const Type /*&*/ r1) { return (r0.d_ <= r1); }   \
    inline bool operator>=(const type /*&*/ r0, const Type /*&*/ r1) { return (r0.d_ >= r1); }   \
    inline bool operator==(const type /*&*/ r0, const Type /*&*/ r1) { return (r0.d_ == r1); }   \
    inline bool operator!=(const type /*&*/ r0, const Type /*&*/ r1) { return (r0.d_ != r1); }

real_define_inequalities(double) real_define_inequalities(float) real_define_inequalities(int)
    real_define_inequalities(long long) real_define_inequalities(unsigned int)
        real_define_inequalities(unsigned long long) real_define_inequalities(unsigned long int)
}  // namespace real

namespace std {
template <>
class numeric_limits<real::type> {
    typedef real::type number_type;

  public:
    static const bool is_specialized = true;
    static number_type(min)() {
        return std::numeric_limits<number_type>::min();
    }
    static number_type(max)() {
        return std::numeric_limits<number_type>::max();
    }
    static number_type lowest() {
        return -(max)();
    }
    static number_type epsilon() {
        return std::numeric_limits<number_type>::epsilon();
    }
    static number_type round_error() {
        return std::numeric_limits<number_type>::round_error();
    }
    static number_type infinity() {
        return std::numeric_limits<number_type>::infinity();
    }
    static number_type quiet_NaN() {
        return std::numeric_limits<number_type>::quiet_NaN();
    }
    static number_type signaling_NaN() {
        return std::numeric_limits<number_type>::signaling_NaN();
    }
    static number_type denorm_min() {
        return std::numeric_limits<number_type>::denorm_min();
    }
    static const int digits = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::digits;
    static const int digits10 = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::digits10;
    static const int radix = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::radix;
    static const int min_exponent = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::min_exponent;
    static const int min_exponent10 = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::min_exponent10;
    static const int max_exponent = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::max_exponent;
    static const int max_exponent10 = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::max_exponent10;
    static const bool has_infinity = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::has_infinity;
    static const bool has_quiet_NaN = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::has_quiet_NaN;
    static const bool has_signaling_NaN = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::has_signaling_NaN;
    static const bool has_denorm_loss = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::has_denorm_loss;
    static const bool is_signed = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::is_signed;
    static const bool is_integer = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::is_integer;
    static const bool is_exact = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::is_exact;
    static const bool is_iec559 = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::is_iec559;
    static const bool is_bounded = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::is_bounded;
    static const bool is_modulo = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::is_modulo;
    static const bool traps = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::traps;
    static const float_denorm_style has_denorm = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::has_denorm;
    static const float_round_style round_style = std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::round_style;
};
}  // namespace std

namespace real {
namespace details {
namespace constant {
static const type e("2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274");
static const type pi("3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");
static const type pi_2(pi / type(2));
static const type pi_4(pi / type(4));
static const type pi_180(pi / type(180));
static const type _1_pi(type(1) / pi);
static const type _2_pi(type(2) / pi);
static const type _180_pi(type(180) / pi);
static const type log2("0.6931471805599453094172321214581765680755001343602552541206800094933936219696947156058633269964186875");
static const type sqrt2("1.41421356237309504880168872420969807856967187537694807317667973799073247846210703885038753432764157273501");
}  // namespace constant
}  // namespace details

inline type abs(const type v) {
    return type(boost::multiprecision::abs(v.d_));
}
inline type acos(const type v) {
    return type(boost::multiprecision::acos(v.d_));
}
inline type asin(const type v) {
    return type(boost::multiprecision::asin(v.d_));
}
inline type atan(const type v) {
    return type(boost::multiprecision::atan(v.d_));
}
inline type ceil(const type v) {
    return type(boost::multiprecision::ceil(v.d_));
}
inline type cos(const type v) {
    return type(boost::multiprecision::cos(v.d_));
}
inline type cosh(const type v) {
    return type(boost::multiprecision::cosh(v.d_));
}
inline type exp(const type v) {
    return type(boost::multiprecision::exp(v.d_));
}
inline type floor(const type v) {
    return type(boost::multiprecision::floor(v.d_));
}
inline type log(const type v) {
    return type(boost::multiprecision::log(v.d_));
}
inline type log10(const type v) {
    return type(boost::multiprecision::log10(v.d_));
}
inline type log2(const type v) {
    return type(boost::multiprecision::log(v.d_)) / type(details::constant::log2);
}
inline type neg(const type v) {
    return type(-1.0) * v;
}
inline type pos(const type v) {
    return v;
}
inline type sin(const type v) {
    return type(boost::multiprecision::sin(v.d_));
}
inline type sinh(const type v) {
    return type(boost::multiprecision::sinh(v.d_));
}
inline type sqrt(const type v) {
    return type(boost::multiprecision::sqrt(v.d_));
}
inline type tan(const type v) {
    return type(boost::multiprecision::tan(v.d_));
}
inline type tanh(const type v) {
    return type(boost::multiprecision::tanh(v.d_));
}
inline type cot(const type v) {
    return type(1) / type(boost::multiprecision::tan(v.d_));
}
inline type sec(const type v) {
    return type(1) / type(boost::multiprecision::cos(v.d_));
}
inline type csc(const type v) {
    return type(1) / type(boost::multiprecision::sin(v.d_));
}
inline type r2d(const type v) {
    return type(v.d_ * type(details::constant::_180_pi));
}
inline type d2r(const type v) {
    return type(v.d_ * type(details::constant::pi_180));
}
inline type d2g(const type v) {
    return type(v.d_ * type(20.0 / 9.0));
}
inline type g2d(const type v) {
    return type(v.d_ * type(9.0 / 20.0));
}
inline type notl(const type v) {
    return (v != type(0) ? type(0) : type(1));
}
inline type frac(const type v) {
    return type(v.d_ - static_cast<long long>(v.d_));
}
inline type trunc(const type v) {
    return type((double)static_cast<long long>(v.d_));
}

inline type modulus(const type v0, const type v1) {
    return type(boost::multiprecision::fmod(v0.d_, v1.d_));
}
inline type pow(const type v0, const type v1) {
    return type(boost::multiprecision::pow(v0.d_, v1.d_));
}
inline type logn(const type v0, const type v1) {
    return type(boost::multiprecision::log(v0.d_)) / type(boost::multiprecision::log(v1.d_));
}
inline type root(const type v0, const type v1) {
    return pow(v0, type(1.0) / v1);
}
inline type atan2(const type v0, const type v1) {
    return type(boost::multiprecision::atan2(v0.d_, v1.d_));
}
inline type max(const type v0, const type v1) {
    return type(boost::multiprecision::max(v0.d_, v1.d_));
}
inline type min(const type v0, const type v1) {
    return type(boost::multiprecision::min(v0.d_, v1.d_));
}

inline bool is_true(const type v) {
    return (v != type(0));
}
inline bool is_false(const type v) {
    return (v == type(0));
}

inline type equal(const type v0x, const type v1x) {
    const type v0(v0x.d_);
    const type v1(v1x.d_);
    static const type epsilon = type(0.0000000001);
    return (abs(v0 - v1) <= (max(type(1), max(abs(v0), abs(v1))) * epsilon)) ? type(1) : type(0);
}

inline type expm1(const type vx) {
    const type v(vx.d_);
    if (abs(v) < type(0.00001))
        return type(v + (0.5 * v * v));
    else
        return type(exp(v) - type(1));
}

inline type nequal(const type v0, const type v1) {
    static const type epsilon = type(0.0000000001);
    return (abs(v0 - v1) > (max(type(1), max(abs(v0), abs(v1))) * epsilon)) ? type(1) : type(0);
}

inline type log1p(const type v) {
    if (v > type(-1)) {
        if (abs(v) > type(0.0001)) {
            return log(type(1) + v);
        } else
            return (type(-0.5) * v + type(1)) * v;
    } else
        return type(std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::quiet_NaN());
}

inline type round(const type v) {
    return ((v < type(0)) ? ceil(v - type(0.5)) : floor(v + type(0.5)));
}

inline type roundn(const type v0, const type v1) {
    const type p10 = pow(type(10), trunc(v1));
    if (v0 < type(0))
        return type(ceil((v0 * p10) - type(0.5)) / p10);
    else
        return type(floor((v0 * p10) + type(0.5)) / p10);
}

inline type hypot(const type v0, const type v1) {
    return sqrt((v0 * v0) + (v1 * v1));
}

inline type shr(const type v0, const type v1) {
    return v0 * (type(1) / pow(type(2), trunc(v1)));
}

inline type shl(const type v0, const type v1) {
    return v0 * pow(type(2), trunc(v1));
}

inline type sgn(const type v) {
    if (v > type(0))
        return type(+1);
    else if (v < type(0))
        return type(-1);
    else
        return type(0);
}

inline type nand(const type v0, const type& v1) {
    return (is_false(v0) || is_false(v1)) ? type(1) : type(0);
}

inline type nor(const type v0, const type& v1) {
    return (is_false(v0) && is_false(v1)) ? type(1) : type(0);
}

inline type xnor(const type v0, const type& v1) {
    const bool v0_true = is_true(v0);
    const bool v1_true = is_true(v1);
    if ((v0_true && v1_true) || (!v0_true && !v1_true))
        return type(1);
    else
        return type(0);
}

inline type erf(type v) {
    const type t = type(1) / (type(1) + type(0.5) * abs(v));

    static const type c[] = {type(1.26551223),  type(1.00002368), type(0.37409196),  type(0.09678418),
                             type(-0.18628806), type(0.27886807), type(-1.13520398), type(1.48851587),
                             type(-0.82215223), type(0.17087277)};

    type result =
        type(1) -
        t * exp((-v * v) - c[0] +
                t * (c[1] +
                     t * (c[2] +
                          t * (c[3] + t * (c[4] + t * (c[5] + t * (c[6] + t * (c[7] + t * (c[8] + t * (c[9]))))))))));

    return (v >= type(0)) ? result : -result;
}

inline type erfc(type v) {
    return type(1) - erf(v);
}
}  // namespace real

namespace exprtk {
namespace details {
namespace numeric {
namespace details {
struct my_real_type_tag;

template <typename T>
inline T const_pi_impl(my_real_type_tag);
template <typename T>
inline T const_e_impl(my_real_type_tag);
}  // namespace details
}  // namespace numeric

inline bool is_true(const real::type v);
inline bool is_false(const real::type v);

template <typename Iterator>
inline bool string_to_real(Iterator& itr_external, const Iterator end, real::type& t,
                           details::numeric::details::my_real_type_tag);
}  // namespace details

namespace rtl {
namespace io {
namespace details {
inline void print_type(const std::string& fmt, const real::type& v,
                       exprtk::details::numeric::details::my_real_type_tag);
}
}  // namespace io
}  // namespace rtl

using details::is_true;
}  // namespace exprtk

#include "exprtk.hpp"

namespace exprtk {
namespace details {
namespace numeric {
namespace details {
struct my_real_type_tag {};

template <>
struct number_type<real::type> {
    typedef my_real_type_tag type;
};

template <>
struct epsilon_type<my_real_type_tag> {
    static inline real::type value() {
        const real::type epsilon = real::type(0.000000000001);
        return epsilon;
    }
};

inline bool is_nan_impl(const real::type& v, my_real_type_tag) {
    return v.d_ != v.d_;
}

template <typename T>
inline T abs_impl(const T v, my_real_type_tag) {
    return real::abs(v);
}
template <typename T>
inline T acos_impl(const T v, my_real_type_tag) {
    return real::acos(v);
}
template <typename T>
inline T acosh_impl(const T v, my_real_type_tag) {
    return real::log(v + real::sqrt((v * v) - real::type(1)));
}
template <typename T>
inline T asin_impl(const T v, my_real_type_tag) {
    return real::asin(v);
}
template <typename T>
inline T asinh_impl(const T v, my_real_type_tag) {
    return real::log(v + real::sqrt((v * v) + real::type(1)));
}
template <typename T>
inline T atan_impl(const T v, my_real_type_tag) {
    return real::atan(v);
}
template <typename T>
inline T atanh_impl(const T v, my_real_type_tag) {
    return (real::log(real::type(1) + v) - log(real::type(1) - v)) / real::type(2);
}
template <typename T>
inline T ceil_impl(const T v, my_real_type_tag) {
    return real::ceil(v);
}
template <typename T>
inline T cos_impl(const T v, my_real_type_tag) {
    return real::cos(v);
}
template <typename T>
inline T cosh_impl(const T v, my_real_type_tag) {
    return real::cosh(v);
}
template <typename T>
inline T exp_impl(const T v, my_real_type_tag) {
    return real::exp(v);
}
template <typename T>
inline T floor_impl(const T v, my_real_type_tag) {
    return real::floor(v);
}
template <typename T>
inline T log_impl(const T v, my_real_type_tag) {
    return real::log(v);
}
template <typename T>
inline T log10_impl(const T v, my_real_type_tag) {
    return real::log10(v);
}
template <typename T>
inline T log2_impl(const T v, my_real_type_tag) {
    return real::log(v) / real::type(real::details::constant::log2);
}
template <typename T>
inline T neg_impl(const T v, my_real_type_tag) {
    return -v;
}
template <typename T>
inline T pos_impl(const T v, my_real_type_tag) {
    return v;
}
template <typename T>
inline T sin_impl(const T v, my_real_type_tag) {
    return real::sin(v);
}
template <typename T>
inline T sinh_impl(const T v, my_real_type_tag) {
    return real::sinh(v);
}
template <typename T>
inline T sqrt_impl(const T v, my_real_type_tag) {
    return real::sqrt(v);
}
template <typename T>
inline T tan_impl(const T v, my_real_type_tag) {
    return real::tan(v);
}
template <typename T>
inline T tanh_impl(const T v, my_real_type_tag) {
    return real::tanh(v);
}
template <typename T>
inline T cot_impl(const T v, my_real_type_tag) {
    return real::type(1) / real::tan(v);
}
template <typename T>
inline T sec_impl(const T v, my_real_type_tag) {
    return real::type(1) / real::cos(v);
}
template <typename T>
inline T csc_impl(const T v, my_real_type_tag) {
    return real::type(1) / real::sin(v);
}
template <typename T>
inline T r2d_impl(const T v, my_real_type_tag) {
    return (v * real::type(real::details::constant::_180_pi));
}
template <typename T>
inline T d2r_impl(const T v, my_real_type_tag) {
    return (v * real::type(real::details::constant::pi_180));
}
template <typename T>
inline T d2g_impl(const T v, my_real_type_tag) {
    return (v * real::type(20.0 / 9.0));
}
template <typename T>
inline T g2d_impl(const T v, my_real_type_tag) {
    return (v * real::type(9.0 / 20.0));
}
template <typename T>
inline T notl_impl(const T v, my_real_type_tag) {
    return (v != real::type(0) ? real::type(0) : real::type(1));
}
template <typename T>
inline T frac_impl(const T v, my_real_type_tag) {
    return (v - static_cast<long long>(v));
}
template <typename T>
inline T trunc_impl(const T v, my_real_type_tag) {
    return real::type(static_cast<long long>(v));
}

template <typename T>
inline T const_pi_impl(my_real_type_tag) {
    return real::details::constant::pi;
}
template <typename T>
inline T const_e_impl(my_real_type_tag) {
    return real::details::constant::e;
}

template <typename T>
inline int to_int32_impl(const T v, my_real_type_tag) {
    return static_cast<int>(v);
}

template <typename T>
inline long long to_int64_impl(const T v, my_real_type_tag) {
    return static_cast<long long int>(v);
}

inline bool is_true_impl(const real::type v) {
    return (0.0 != v);
}

inline bool is_false_impl(const real::type v) {
    return (0.0 == v);
}

template <typename T>
inline T expm1_impl(const T v, my_real_type_tag) {
    if (abs(v) < T(0.00001))
        return v + (T(0.5) * v * v);
    else
        return exp(v) - T(1);
}

template <typename T>
inline T nequal_impl(const T v0, const T v1, my_real_type_tag) {
    const T epsilon = epsilon_type<T>::value();
    const T eps_norm =
        (std::max(T(1), std::max(abs_impl(v0, my_real_type_tag()), abs_impl(v1, my_real_type_tag()))) * epsilon);
    return (abs_impl(v0 - v1, my_real_type_tag()) > eps_norm) ? T(1) : T(0);
}

template <typename T>
inline T sgn_impl(const T v, my_real_type_tag) {
    if (v > T(0))
        return T(+1);
    else if (v < T(0))
        return T(-1);
    else
        return T(0);
}

template <typename T>
inline T log1p_impl(const T v, my_real_type_tag) {
    if (v > T(-1)) {
        if (abs_impl(v, my_real_type_tag()) > T(0.0001)) {
            return log_impl(T(1) + v, my_real_type_tag());
        } else
            return (T(-0.5) * v + T(1)) * v;
    } else
        return T(std::numeric_limits<T>::quiet_NaN());
}

template <typename T>
inline T erf_impl(T v, my_real_type_tag) {
    const T t = T(1) / (T(1) + T(0.5) * abs_impl(v, my_real_type_tag()));

    static const T c[] = {T(1.26551223), T(1.00002368),  T(0.37409196), T(0.09678418),  T(-0.18628806),
                          T(0.27886807), T(-1.13520398), T(1.48851587), T(-0.82215223), T(0.17087277)};

    T result =
        T(1) -
        t * exp_impl((-v * v) - c[0] +
                         t * (c[1] +
                              t * (c[2] +
                                   t * (c[3] +
                                        t * (c[4] + t * (c[5] + t * (c[6] + t * (c[7] + t * (c[8] + t * (c[9]))))))))),
                     my_real_type_tag());

    return (v >= T(0)) ? result : -result;
}

template <typename T>
inline T erfc_impl(T v, my_real_type_tag) {
    return T(1) - erf_impl(v, my_real_type_tag());
}

template <typename T>
inline T ncdf_impl(T v, my_real_type_tag) {
    T cnd = T(0.5) *
            (T(1) + erf_impl(abs_impl(v, my_real_type_tag()) / T(real::details::constant::sqrt2), my_real_type_tag()));
    return (v < T(0)) ? (T(1) - cnd) : cnd;
}

template <typename T>
inline T modulus_impl(const T v0, const T v1, my_real_type_tag) {
    return modulus(v0, v1);
}

template <typename T>
inline T pow_impl(const T v0, const T v1, my_real_type_tag) {
    return real::pow(v0, v1);
}

template <typename T>
inline T logn_impl(const T v0, const T v1, my_real_type_tag) {
    return log(v0) / log(v1);
}

template <typename T>
inline T sinc_impl(T v, my_real_type_tag) {
    if (abs_impl(v, my_real_type_tag()) >= std::numeric_limits<T>::epsilon())
        return (sin_impl(v, my_real_type_tag()) / v);
    else
        return T(1);
}

template <typename T>
inline T xor_impl(const T v0, const T v1, my_real_type_tag) {
    return (is_false_impl(v0) != is_false_impl(v1)) ? T(1) : T(0);
}

template <typename T>
inline T xnor_impl(const T v0, const T v1, my_real_type_tag) {
    const bool v0_true = is_true_impl(v0);
    const bool v1_true = is_true_impl(v1);
    if ((v0_true && v1_true) || (!v0_true && !v1_true))
        return T(1);
    else
        return T(0);
}

template <typename T>
inline T equal_impl(const T v0, const T v1, my_real_type_tag) {
    const T epsilon = epsilon_type<T>::value();
    const T eps_norm = (max(T(1), max(abs_impl(v0, my_real_type_tag()), abs_impl(v1, my_real_type_tag()))) * epsilon);
    return (abs_impl(v0 - v1, my_real_type_tag()) <= eps_norm) ? T(1) : T(0);
}

template <typename T>
inline T round_impl(const T v, my_real_type_tag) {
    return ((v < T(0)) ? ceil(v - T(0.5)) : floor(v + T(0.5)));
}

template <typename T>
inline T roundn_impl(const T v0, const T v1, my_real_type_tag) {
    const int index = std::max<int>(0, std::min<int>(pow10_size - 1, (int)floor(v1)));
    const T p10 = T(pow10[index]);
    if (v0 < T(0))
        return T(ceil((v0 * p10) - T(0.5)) / p10);
    else
        return T(floor((v0 * p10) + T(0.5)) / p10);
}

template <typename T>
inline bool is_integer_impl(const T v, my_real_type_tag) {
    return (T(0) == modulus_impl(v, T(1), my_real_type_tag()));
}

template <typename T>
inline T root_impl(const T v0, const T v1, my_real_type_tag) {
    return pow(v0, T(1) / v1);
}

template <typename T>
inline T hypot_impl(const T v0, const T v1, my_real_type_tag) {
    return sqrt((v0 * v0) + (v1 * v1));
}

template <typename T>
inline T atan2_impl(const T v0, const T v1, my_real_type_tag) {
    return std::atan2(v0.d_, v1.d_);
}

template <typename T>
inline T shr_impl(const T v0, const T v1, my_real_type_tag) {
    return v0 * (T(1) / pow(T(2), v1));
}

template <typename T>
inline T shl_impl(const T v0, const T v1, my_real_type_tag) {
    return v0 * pow(T(2), v1);
}

template <typename T>
inline T and_impl(const T v0, const T v1, my_real_type_tag) {
    return (is_true_impl(v0) && is_true_impl(v1)) ? T(1) : T(0);
}

template <typename T>
inline T nand_impl(const T v0, const T v1, my_real_type_tag) {
    return (is_false_impl(v0) || is_false_impl(v1)) ? T(1) : T(0);
}

template <typename T>
inline T or_impl(const T v0, const T v1, my_real_type_tag) {
    return (is_true_impl(v0) || is_true_impl(v1)) ? T(1) : T(0);
}

template <typename T>
inline T nor_impl(const T v0, const T v1, my_real_type_tag) {
    return (is_false_impl(v0) && is_false_impl(v1)) ? T(1) : T(0);
}
}  // namespace details
}  // namespace numeric

template <typename Iterator>
inline bool string_to_real(Iterator& itr_external, const Iterator end, real::type& t,
                           details::numeric::details::my_real_type_tag) {
    typename numeric::details::number_type<boost::multiprecision::cpp_dec_float_100>::type num_type;
    return string_to_real<Iterator, double>(itr_external, end, t.d_, num_type);
}

inline bool is_true(const real::type v) {
    return real::is_true(v);
}
inline bool is_false(const real::type v) {
    return real::is_false(v);
}
}  // namespace details

namespace rtl {
namespace io {
namespace details {
inline void print_type(const std::string& fmt, const real::type v,
                       exprtk::details::numeric::details::my_real_type_tag) {
    printf(fmt.c_str(), (double)v);
}
}  // namespace details
}  // namespace io
}  // namespace rtl
}  // namespace exprtk
