#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
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

bool operator <(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator()) < (rhs.Numerator() * lhs.Denominator());
}

bool operator >(const Rational& lhs, const Rational& rhs) {
    int p_l = 0;
    int p_r = 0;
    p_l = ;
    p_r = x;
    return (lhs.Numerator() * rhs.Denominator()) > (lhs.Numerator() * rhs.Denominator());
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}