#include<iostream>
using namespace std;

class Rectangle {
private:
    double length, width;
public:
	Rectangle(){
		cout<<"Rectangle default constructor is called "<<endl;
		length=1;
		width=2;
		
	}
	Rectangle( double l){
		cout<<"Rectangle parameterized construcor is called with length "<<l<<" and  has default width 2"<<endl;
		length=l;
		width=9;
	
		
	}
	Rectangle( double l,double w){
		cout<<"Rectangle parameterized construcor is called with length "<<l<<" and "<<"width "<<w<<endl;
		length=l;
		width=w;
	}
	
	
    void setLength(double l) {
        length = (l > 0) ? l : 1;
    }

    void setWidth(double w) {
        width = (w > 0) ? w : 2;
    }

    void set(double l, double w) {
        setLength(l);
        setWidth(w);
    }

    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    double getPerimeter() const {
        return 2 * (length + width);
    }

    double getArea() const {
        return length * width;
    }
};

void print(const Rectangle& r) {

    cout << "Length: " << r.getLength() << endl;
    cout << "Width: " << r.getWidth() << endl;
    cout << "Perimeter: " << r.getPerimeter() << endl;
    cout << "Area: " << r.getArea() << endl;
    
    cout<<endl;
}

int main() {
    Rectangle r1, r2(45.3) ,r3(25.1,9.2);

    cout<<endl;
    cout<<"Rectangle R1"<<endl;
    print(r1);
    cout<<"Rectangle R2"<<endl;
    print(r2);
    cout<<"Rectangle R3"<<endl;
    print(r3);
    return 0;
}
