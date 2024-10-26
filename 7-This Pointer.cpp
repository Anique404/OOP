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
	Rectangle( double length){
		cout<<"Rectangle parameterized construcor is called with length "<<length<<" and  has default width 2"<<endl;
		this->length=length;
		width=2;
	
		
	}
	Rectangle( double length,double width){
		cout<<"Rectangle parameterized construcor is called with length "<<length<<" and "<<"width "<<width<<endl;
		this->length=length;
		this->width=width;
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
    
    ~Rectangle(){
		cout<<"The Destructor is called with length "<<length<<" and width "<<width<<endl;	
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
  Rectangle r1, r2(45.3) ,r3(25.1,9.2) ;
    
	// default constructor
	Rectangle r4=r1;
	//default constructor
	Rectangle r5=r2;

    cout<<endl;
    cout<<"Rectangle R1"<<endl;
    print(r1);
    cout<<"Rectangle R2"<<endl;
    print(r2);
    cout<<"Rectangle R3"<<endl;
    print(r3);
    cout<<"Default Copy constructor"<<endl;
    cout<<"Rectangle R4"<<endl;
    print(r4);
    cout<<"DefaultCopy constructor"<<endl;
    cout<<"Rectangle R5"<<endl;
    print(r5);
    return 0;
}
