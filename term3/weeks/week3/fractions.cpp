#pragma once

#include <numeric>

using namespace std;

class [[maybe_unused]] Rational final
{
public:

    explicit Rational(int num = 0, int den = 1)
    {
        numerator = num;
        denominator = den;
    };

    Rational(const Rational &other) = default;

    Rational &operator=(const Rational &other) = default;

    Rational &operator+=(const Rational &rha)
    {
        this->numerator = this->numerator * rha.denominator + rha.numerator * this->denominator;
        this->denominator *= rha.denominator;
        correction(*this);
        return *this;
    }

    Rational &operator+=(int num)
    {
        return (*this += Rational(num, 1));
    }

    Rational &operator-=(const Rational &rha)
    {
        this->numerator = this->numerator * rha.denominator - rha.numerator * this->denominator;
        this->denominator *= rha.denominator;
        correction(*this);
        return (*this);
    }

    Rational &operator-=(int num)
    {
        return (*this -= Rational(num, 1));
    }

    Rational &operator*=(const Rational &rha)
    {
        this->numerator *= rha.numerator;
        this->denominator *= rha.numerator;
        correction(*this);
        return *this;
    }

    Rational &operator*=(int num)
    {
        return (*this *= Rational(num, 1));
    }

    Rational &operator/=(const Rational &rha)
    {
        this->numerator *= rha.denominator;
        this->denominator *= rha.numerator;
        correction(*this);
        return *this;
    }

    Rational &operator/=(int num)
    {
        return (*this /= Rational(num, 1));
    }

    Rational operator+() const
    {
        auto res = Rational(this->numerator, this->denominator);
        correction(res);
        return res;
    }

    Rational operator-() const
    {
        auto res = Rational(this->numerator * -1, this->denominator);
        correction(res);
        return res;
    }

    Rational operator*(const Rational &other) const
    {
        auto res = Rational(this->numerator * other.numerator, this->denominator * other.denominator);
        correction(res);
        return res;
    }

    Rational operator/(const Rational &other) const
    {
        auto res = Rational(this->numerator * other.denominator, this->denominator *
                                                                 other.numerator);
        correction(res);
        return res;
    }

    explicit operator double() const
    {
        return static_cast<double>(numerator) / static_cast<double>(denominator);
    }

    [[nodiscard]] double toDouble() const
    {
        return static_cast<double>(numerator) / static_cast<double>(denominator);
    }

private:

    static void correction(Rational &frac)
    {
        if (frac.numerator > frac.denominator)
            return;

        auto tmp = gcd(frac.numerator, frac.denominator);
        frac.numerator /= tmp;
        frac.denominator /= tmp;
    }

    friend Rational operator+(const Rational &lha, const Rational &rha)
    {
        auto res = lha;
        return res += rha;
    };

    friend Rational operator+(const Rational &rha, const int &lha)
    {
        return Rational(lha, 1) += rha;
    };

    friend Rational operator+(const int &rha, const Rational &lha)
    {
        return Rational(rha, 1) += lha;
    };

    friend Rational operator-(const Rational &lha, const Rational &rha)
    {
        auto res = lha;
        return res -= rha;
    }

    friend Rational operator-(const int &lha, const Rational &rha)
    {
        return Rational(lha, 1) -= rha;
    };

    friend Rational operator-(const Rational &lha, const int &rha)
    {
        return Rational(rha * -1, 1) += lha;
    };

    friend Rational operator*(const int &lha, const Rational &rha)
    {
        return Rational(lha, 1) *= rha;
    };

    friend Rational operator*(const Rational &lha, const int &rha)
    {
        return Rational(rha, 1) *= lha;
    };

    friend Rational operator/(const int &lha, const Rational &rha)
    {
        return Rational(lha, 1) /= rha;
    };

    friend Rational operator/(const Rational &lha, const int &rha)
    {
        return lha / Rational(rha, 1);
    };

    friend bool operator<(const Rational &lha, const Rational &rha)
    {
        return (lha.numerator * rha.denominator < rha.numerator * lha.denominator);
    }

    friend bool operator<(const int &lh, const Rational &rha)
    {
        return (Rational(lh, 1) < rha);
    }

    friend bool operator<(const Rational &lha, const int &rh)
    {
        return (lha < Rational(rh, 1));
    }

    friend bool operator>(const Rational &lha, const Rational &rha)
    {
        return (lha.numerator * rha.denominator > rha.numerator * lha.denominator);
    }

    friend bool operator>(const int &lha, const Rational &rha)
    {
        return Rational(lha, 1) > rha;
    }

    friend bool operator>(const Rational &lha, const int &rha)
    {
        return lha > Rational(rha, 1);
    }

    friend bool operator<=(const Rational &lha, const Rational &rha)
    {
        return (lha.numerator * rha.denominator <= rha.numerator * lha.denominator);
    }

    friend bool operator<=(const int &lha, const Rational &rha)
    {
        return Rational(lha, 1) <= rha;
    }

    friend bool operator<=(const Rational &lha, const int &rha)
    {
        return lha <= Rational(rha, 1);
    }

    friend bool operator>=(const Rational &lha, const Rational &rha)
    {
        return (lha.numerator * rha.denominator >= rha.numerator * lha.denominator);
    }

    friend bool operator>=(const int &lha, const Rational &rha)
    {
        return Rational(lha, 1) >= rha;

    }

    friend bool operator>=(const Rational &lha, const int &rha)
    {
        return lha >= Rational(rha, 1);
    }

    friend bool operator!=(const Rational &lha, const Rational &rha)
    {
        return !(lha == rha);
    }

    friend bool operator!=(const int &lha, const Rational &rha)
    {
        return Rational(lha, 1) != rha;
    }

    friend bool operator!=(const Rational &lha, const int &rha)
    {
        return lha != Rational(rha, 1);
    }

    friend bool operator==(const Rational &lha, const Rational &rha)
    {
        return rha.toDouble() == lha.toDouble();
    }

    friend bool operator==(const int &lha, const Rational &rha)
    {
        return Rational(lha, 1) == rha;
    }

    friend bool operator==(const Rational &lha, const int &rha)
    {
        return lha == Rational(rha, 1);
    }

    int numerator;
    int denominator;
};