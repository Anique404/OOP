#include <iostream>
#include <cmath>
using namespace std;

class Rational {
    int num, denom;
    friend istream &operator>>(istream &input, Rational &s);
    friend ostream &operator<<(ostream &output, const Rational &s);

    void GCD() {
        denom = (denom != 0) ? denom : 1;
        int r = fmod(num, denom);
        while (r != 0) {
            num = denom;
            denom = r;
            r = fmod(num, denom);
        }

        num /= denom;
        denom /= denom;

        if (denom < 0) {
            denom = -denom;
            num = -num;
        }
    }

public:
    Rational() : num(2), denom(1) {}

    Rational(int n) : num(n), denom(3) {}

    Rational(int n, int d) : num(n), denom(d) {}

    void setnum(int n) {
        num = n;
        GCD();
    }

    void setdenom(int d) {
        denom = d;
        GCD();
    }

    void set(int n, int d) {
        num = n;
        denom = d;
        GCD();
    }

    ~Rational() {}

    
};

istream &operator>>(istream &input, Rational &s) {
    input >> s.num;
    do {
        input >> s.denom;
    } while (s.denom == 0);
    return input;
}

ostream &operator<<(ostream &output, const Rational &s) {
    output << endl;
    output << "Rational = " << s.num << "/" << s.denom << endl;
    output << endl;
    return output;
}

int main() {
    Rational r1, r2(14), r3(25, 5), r4;

    cin >> r1;
    cout << r1;
    cout << r2;

    

    return 0;
}

