#include <iostream>
#include <sstream>
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

    void SetFract(int num, int denom) {
        p = num;
        q = denom;
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

ostream& operator <<(ostream &out, const Rational& rat) {
    out << rat.Numerator() << "/" << rat.Denominator();
    return out;
}

istream& operator >>(istream &input, Rational& rat) {
   if(input) {
       int loc_p = rat.Numerator();
       int loc_q = rat.Denominator();
       input >> loc_p;
       input.ignore(1);
       input >> loc_q;
       Rational loc(loc_p, loc_q);
       rat.SetFract(loc.Numerator(), loc.Denominator());
    }
   return input;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }
    Rational r1, r2, r3;
    cin >> r1 >> r2 >> r3;
    cout << r1 << " " << r2 << " " << r3 << endl;
    cout << "OK" << endl;
    return 0;
}