//#pragma once
//
//#include <QtCore/QObject>
//#include <QtCore/QString>
//
// class Fraction : public QObject {
//    Q_OBJECT
//
//  public:
//    Fraction() : val() {}
//
//    Fraction(const Fraction& oth) : val(oth.val) {}
//
//    Fraction& operator=(const Fraction& oth) {
//        val = oth.val;
//        return *this;
//    }
//
//    explicit Fraction(const QString str) {
//        int div = str.indexOf('/');
//        if (div == -1) {
//            val = boost::rational<long long>(str.toLongLong(), 1LL);
//            return;
//        }
//        val = boost::rational<long long>(str.mid(0, div).toLongLong(), str.mid(div + 1).toLongLong());
//    }
//
//    bool isZero() const {
//        return val.numerator() == 0;
//    }
//
//    QString toKaTex() const {
//        if (val.numerator() == 0)
//            return "0";
//        if (val.denominator() == 1)
//            return QString::number(val.numerator());
//        return QString(R"(\dfrac{%1})").arg(val.numerator()) + QString("{%1}").arg(val.denominator());
//    }
//
//    QString toKaTexAsCoefficient() const {
//        if (val.numerator() == 0)
//            return "";
//        if (val.denominator() == 1) {
//            if (val.numerator() == 1)
//                return "";
//            if (val.numerator() == -1)
//                return "-";
//            return QString::number(val.numerator());
//        }
//        return QString(R"(\dfrac{%1})").arg(val.numerator()) + QString("{%1}").arg(val.denominator());
//    }
//
//    QString toKaTexWithPositiveSign() const {
//        if (val.numerator() == 0)
//            return "+0";
//        QString head;
//        if (val.numerator() > 0)
//            head = "+";
//        if (val.denominator() == 1)
//            return head + QString::number(val.numerator());
//        return head + QString(R"(\dfrac{%1})").arg(val.numerator()) + QString("{%1}").arg(val.denominator());
//    }
//
//    QString toKaTexAsCoefficientWithPositiveSign() const {
//        if (val.numerator() == 0)
//            return "";
//        QString head;
//        if (val.numerator() > 0)
//            head = "+";
//        if (val.denominator() == 1) {
//            if (val.numerator() == 1)
//                return "+";
//            if (val.numerator() == -1)
//                return "-";
//            return head + QString::number(val.numerator());
//        }
//        return head + QString(R"(\dfrac{%1})").arg(val.numerator()) + QString("{%1}").arg(val.denominator());
//    }
//
//    Fraction operator+(const Fraction& oth) const {
//        Fraction res;
//        res.val = val + oth.val;
//        return res;
//    }
//
//    Fraction operator-(const Fraction& oth) const {
//        Fraction res;
//        res.val = val - oth.val;
//        return res;
//    }
//
//    Fraction operator*(const Fraction& oth) const {
//        Fraction res;
//        res.val = val * oth.val;
//        return res;
//    }
//
//    Fraction operator/(const Fraction& oth) const {
//        Fraction res;
//        res.val = val / oth.val;
//        return res;
//    }
//
//    bool operator==(const Fraction& oth) const {
//        return val == oth.val;
//    }
//
//    bool operator!=(const Fraction& oth) const {
//        return val != oth.val;
//    }
//
//    bool operator<(const Fraction& oth) const {
//        return val < oth.val;
//    }
//
//    bool operator<=(const Fraction& oth) const {
//        return val <= oth.val;
//    }
//
//    bool operator>(const Fraction& oth) const {
//        return val > oth.val;
//    }
//
//    bool operator>=(const Fraction& oth) const {
//        return val >= oth.val;
//    }
//
//  private:
//    boost::rational<long long> val;
//};