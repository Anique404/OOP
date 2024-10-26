#include <iostream>
#include <cmath>
using namespace std;

class Rational {
    int num, denom;
    friend void Print(Rational &);

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
    Rational() : num(2), denom(1) {
        cout << "The Default Constructor has Numinator is " << num << " and Denominator is " << denom << endl;
    }

    Rational(int n) : num(n), denom(3) {
        cout << "The Single Argument Constructor has Numinator is " << num << " and Denominator is " << denom << endl;
    }

    Rational(int n, int d) : num(n), denom(d) {
        cout << "The Multiple Argument Constructor has Numinator is " << num << " and Denominator is " << denom << endl;
    }

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

   Rational Add(const Rational &r) {
        int n = num * r.denom + r.num * denom;
        int d = denom * r.denom;
        
            
        return Rational(n, d);
    }

     Rational  Sub(const Rational &r) {
        int n = num * r.denom - r.num * denom;
        int d = denom * r.denom;

        return Rational(n, d);
    }

  Rational  Mult(const Rational &r) {
        int n = num * r.num;
        int d = denom * r.denom;

        return Rational(n, d);
    }

     Rational  Dev(const Rational &r)  {
        int n = num * r.denom;
        int d = denom * r.num;

        return Rational(n, d);
    }

    ~Rational() {
        cout << "Destructor is called has Numerator " << num << " and Denominator " << denom << endl;
    }
};

void Print(Rational &r) {
    cout << endl;
    cout << "Rational = " << r.num << "/" << r.denom << endl;
    cout << endl;
}

int main() {
    Rational r1, r2(4), r3(25, 5), r4;
    
    cout<<endl;
    cout<<"GCD of R1"<<endl;

    r1.set(25,-4);
    Print(r1);
    
    cout<<"GCD of R2"<<endl;
    
    r2.set(29,-19);
    Print(r2);

    cout << endl;
    cout << "Add R1 and R2 " << endl;
    cout << endl;
    
    
    r4 = r1.Add(r2);
    Print(r4);

    cout<<endl;
    cout<<"GCD of R1"<<endl;

    r1.set(21,-4);
    Print(r1);
    
    cout<<endl;
    cout<<"GCD of R3"<<endl;

    r3.set(15,-4);
    Print(r3);

    cout << endl;
    cout << "Subtract R1 and R3 " << endl;
    cout << endl;

    r4 = r1.Sub(r3);
    Print(r4);

    return 0;
}


