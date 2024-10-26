#include <iostream>
#include <cmath>
using namespace std;

class Rational {
    int num, denom;
    friend void Print(Rational &);
    friend void input( Rational& );

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
    Rational() : num(29), denom(5) {
        //cout << "The Default Constructor has Numinator is " << num << " and Denominator is " << denom << endl;
    }

    Rational(int n) : num(n), denom(3) {
      //  cout << "The Single Argument Constructor has Numinator is " << num << " and Denominator is " << denom << endl;
    }

    Rational(int n, int d) : num(n), denom(d) {
       // cout << "The Multiple Argument Constructor has Numinator is " << num << " and Denominator is " << denom << endl;
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


    ~Rational() {
      //  cout << "Destructor is called has Numerator " << num << " and Denominator " << denom << endl;
    }
    
    Rational & operator--(){
    	num=num+denom;
    	GCD();
    	return *this;
    	
	}
	
	const Rational   operator--(int){
		Rational temp=*this;
    	num=num+denom;
    	GCD();
    	return temp;
	}

    
};

void Print(Rational &r) {
    cout << endl;
    cout << "Rational = " << r.num << "/" << r.denom << endl;
    cout << endl;
}

void input( Rational& s){
	//int n,d;
	cout<<"Enter Numinator = ";
	cin>>s.num;
	do{
	cout<<"Enter Denominator = ";
	cin>>s.denom;
	}while(s.denom==0);
	
//	s.set(n,d);
	
}

int main() {
    Rational r1, r2(14), r3(25, 5), r4;
    
    Print(r1);
    Print(r2);
    
    r2=--r1;
    cout<<" R1 "<<endl;
    Print(r1);
    cout<<" R2 "<<endl;
    Print(r2);
    
    r1=r2--;
    cout<<" R1 "<<endl;
    Print(r1);
    cout<<" R2 "<<endl;
    Print(r2);
  
}
