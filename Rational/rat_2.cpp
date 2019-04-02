#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        int gcf = 0;
        gcf = CalcGCF(numerator, denominator);
        if(denominator < 0) {
            numerator = -numerator;
        }
        p = numerator/gcf;
        q = abs(denominator/gcf);
    }

    int Numerator() const {
        // Реализуйте этот метод
        return p;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return q;
    }

    int CalcGCF(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (a > 0 && b > 0) {
            if (a > b) {
              a %= b;
            } else {
              b %= a;
            }
          }
        return b + a;
    }

private:
    // Добавьте поля
    int p;
    int q;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    if((lhs.Denominator() == rhs.Denominator()) && (lhs.Numerator() == rhs.Numerator())) {
        return true;
    }
    else {
        return false;
    }
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int sub_num = 0;
    int sub_denom = 0;
    sub_num = lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator();
    sub_denom = lhs.Denominator() * rhs.Denominator();
    return Rational(sub_num, sub_denom);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int sub_num = 0;
    int sub_denom = 0;
    sub_num = lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator();
    sub_denom = lhs.Denominator() * rhs.Denominator();
    return Rational(sub_num, sub_denom);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    int sub_num = 0;
    int sub_denom = 0;
    sub_num = lhs.Numerator() * rhs.Numerator();
    sub_denom = lhs.Denominator() * rhs.Denominator();
    return Rational(sub_num, sub_denom);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    int sub_num = 0;
    int sub_denom = 0;
    sub_num = lhs.Numerator() * rhs.Denominator();
    sub_denom = lhs.Denominator() * rhs.Numerator();
    return Rational(sub_num, sub_denom);
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
