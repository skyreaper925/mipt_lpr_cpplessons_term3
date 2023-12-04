//
// Created by user on 18.11.2023.
//

#define MIPT_LPR_CPPLESSONS_TERM3_RATIONAL_HPP

#include <numeric>

class [[maybe_unused]] Rational final
{
public:
    explicit Rational(int num = 0, int den = 1);

    Rational(const Rational &other);

    Rational &operator=(const Rational &other);

    Rational &operator+=(const Rational &rha);

    Rational &operator+=(int num);

    Rational &operator-=(const Rational &rha);

    Rational &operator-=(int num);

    Rational &operator*=(const Rational &rha);

    Rational &operator*=(int num);

    Rational &operator/=(const Rational &rha);

    Rational &operator/=(int num);

    Rational operator+() const;

    Rational operator-() const;

    Rational operator*(const Rational &other) const;

    Rational operator/(const Rational &other) const;

    explicit operator double() const;

    [[nodiscard]] double toDouble() const;


    int denominator;
    int numerator;

private:

    void correction(Rational &r)
    {
        int gcd = std::gcd(r.numerator, r.denominator);
        r.numerator /= gcd;
        r.denominator /= gcd;
        if (r.denominator < 0)
        {
            r.numerator *= -1;
            r.denominator *= -1;
        }
    }

public:

    explicit Rational(int num = 0, int den = 1);

    Rational(const Rational &other);

    Rational &operator=(const Rational &other);

    Rational &operator+=(const Rational &rha);

    Rational &operator+=(int num);

    Rational &operator-=(const Rational &rha);

    Rational &operator-=(int num);

    Rational &operator*=(const Rational &rha);

    Rational &operator*=(int num);

    Rational &operator/=(const Rational &rha);

    Rational &operator/=(int num);

    Rational operator+() const;

    Rational operator-() const;

    Rational operator*(const Rational &other) const;

    Rational operator/(const Rational &other) const;

    explicit operator double() const;

    [[nodiscard]] double toDouble() const;

private:

    static void correction(Rational &frac)
    {
        if (frac.numerator > frac.denominator)
            return;

        auto tmp = std::gcd(frac.numerator, frac.denominator);
        frac.numerator /= tmp;
        frac.denominator /= tmp;
    }

    friend Rational operator+(const Rational &lha, const Rational &rha);

    friend Rational operator+(const Rational &rha, const int &lha);

    friend Rational operator+(const int &rha, const Rational &lha);

    friend Rational operator-(const Rational &lha, const Rational &rha);

    friend Rational operator-(const int &lha, const Rational &rha);

    friend Rational operator-(const Rational &lha, const int &rha);

    friend Rational operator*(const int &lha, const Rational &rha);

    friend Rational operator*(const Rational &lha, const int &rha);

    friend Rational operator/(const int &lha, const Rational &rha);

    friend Rational operator/(const Rational &lha, const int &rha);

    friend bool operator<(const Rational &lha, const Rational &rha);

    friend bool operator<(const int &lh, const Rational &rha);

    friend bool operator<(const Rational &lha, const int &rh);

    friend bool operator>(const Rational &lha, const Rational &rha);

    friend bool operator>(const int &lha, const Rational &rha);

    friend bool operator>(const Rational &lha, const int &rha);

    friend bool operator<=(const Rational &lha, const Rational &rha);

    friend bool operator<=(const int &lha, const Rational &rha);

    friend bool operator<=(const Rational &lha, const int &rha);

    friend bool operator>=(const Rational &lha, const Rational &rha);

    friend bool operator>=(const int &lha, const Rational &rha);

    friend bool operator>=(const Rational &lha, const int &rha);

    friend bool operator!=(const Rational &lha, const Rational &rha);

    friend bool operator!=(const int &lha, const Rational &rha);

    friend bool operator!=(const Rational &lha, const int &rha);

    friend bool operator==(const Rational &lha, const Rational &rha);

    friend bool operator==(const int &lha, const Rational &rha);

    friend bool operator==(const Rational &lha, const int &rha);
};
