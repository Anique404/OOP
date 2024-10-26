#include <iostream>
#include <cmath>
using namespace std;

class Rational {
    int num, denom;
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
        
        if(denom<0){
        	denom=-denom;
        	num=-num;
		}
	
    }

public:
    Rational() : num(2), denom(5) {
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
    
     int getnum()  {
        return num;
    }

    int getdenom()  {
        return denom;
    
    }

    ~Rational() {
        cout << "Destructor is called has Numerator " << num << " and Denominator " << denom << endl;
    }
       	
};




void Print( Rational &r) {
	cout<<endl;
    cout << "Rational 1 = " << r.getnum() << "/" << r.getdenom() << endl;
    cout<<endl;
}

int main() {
    Rational r1, r2(4), r3(25, 5);

    cout << "The result of 1st Rational Number " << endl;
    Print(r1);

    cout << "Updating 1st Rational Number" << endl;
    r1.setnum(-93);
    r1.setdenom(52);
    Print(r1);
   

    cout << "The result of 2nd Rational Number " << endl;
    Print(r2);

    cout << "Updating 2nd Rational Number" << endl;
    r2.setdenom(-39);
  
    Print(r2);

    cout << "The result of 3rd Rational Number " << endl;
    Print(r3);

    cout << "Updating 3rd Rational Number" << endl;
    r3.set(137, -11);

    Print(r3);
    
     

    return 0;
}


