#include<iostream>
using namespace std;

class Rectangle {
private:
    double length, width;

public:
	
    void setLength(double l) {
        length = (l > 0) ? l : 1;
    }

    void setWidth(double w) {
        width = (w > 0) ? w : 1;
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

void print(const Rectangle& r1, const Rectangle& r2) {
    cout << "Rectangle 1:\n";
    cout << "Length: " << r1.getLength() << endl;
    cout << "Width: " << r1.getWidth() << endl;
    cout << "Perimeter: " << r1.getPerimeter() << endl;
    cout << "Area: " << r1.getArea() << endl;

    cout << "\nRectangle 2:\n";
    cout << "Length: " << r2.getLength() << endl;
    cout << "Width: " << r2.getWidth() << endl;
    cout << "Perimeter: " << r2.getPerimeter() << endl;
    cout << "Area: " << r2.getArea() << endl;
}

int main() {
    Rectangle r1, r2;

    r1.set(2.5, 3.9);
    r2.set(2.4, 0); 

    print(r1, r2);

    return 0;
}

