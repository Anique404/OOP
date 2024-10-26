#include<iostream>
using namespace std;

class Point{
	
	int x,y;
	friend istream & operator>>( istream & input, Point & p);
	friend ostream & operator<<( ostream & output,const  Point & p);
	
	public:
		
		Point();
		Point(int);
		Point(int,int);
		Point(const Point &);
		~Point();
		
		void setx(int);
		void sety(int);
		void set(int,int);
		
		int getx();
		int gety();
		
		int PointArea() const;
};

Point::Point():x(2),y(3){	
	cout<<"Default constructor of Point is called"<<endl;	
}

Point::Point(int xx) : x(xx),y(3){
	cout<<"Convert constructor of Point is called"<<endl;
}

Point::Point(int xx,int yy) : x(xx),y(yy){
	cout<<"Parameterized constructor of Point is called"<<endl;
}

Point::Point(const Point & p){
	x=p.x;
	y=p.y;
	cout<<"Copy constructor of Point is called"<<endl;
}

void Point:: setx(int xx){
	x=xx;
}

void Point:: sety(int yy){
	y=yy;
}

void Point:: set(int xx,int yy){
	x=xx;
	y=yy;
}

int Point:: getx(){
	return x;
}

int Point:: gety(){
	return y;
}

int Point::PointArea() const{
	return 0;
}

Point::~Point(){	
	cout<<"Point Destructor is called"<<endl;	
}

istream & operator>>( istream & input, Point & p){
	cout<<"Enter value of x = " ;
	input>>p.x;
	
	cout<<"Enter value of y = " ;
	input>>p.y;
	
	return input;
}

ostream & operator<<( ostream & output,const  Point & p){
	output<<"the value of x = " ;
	output<<p.x<<endl;
	
	output<<"the value of y = " ;
	output<<p.y<<endl;
	
	output<<"the Area of Point is = " ;
	output<<p.PointArea()<<endl;
	
	return output;
}

class Circle{
	int r;

	static const double pi;
	friend istream & operator>>(istream & input, Circle & c);
	friend ostream & operator<<(ostream & output,const  Circle & c);
	
	public:
		
		Circle();
		Circle(int);
		Circle(const Circle &);
		~Circle();
		
		void setr(int);
		int getr();
		
		double getDiameter()const;
     	double getArea()const;
	    double getCircumference()const;
	
};

const double Circle:: pi = 3.14159;

Circle::Circle():r(5){
	cout<<"Default constructor of Circle is called"<<endl;
}

Circle::Circle(int rr):r(rr){
	cout<<"1 Parmeterize constructor of Circle is called"<<endl;
}

Circle::Circle(const Circle & c):r(c.r){
	cout<<"Copy constructor of Circle  is called"<<endl;
}

void Circle::setr(int rr){
	r=rr;
}

int Circle::getr(){
	return r;
}

double Circle::getDiameter()const {
	return 2 * r;
}

double Circle::getArea()const {
	return pi * (r * r);
}

double Circle::getCircumference()const {
	return 2 * pi * r;
}


Circle::~Circle(){	
	cout<<"Circle Destructor is called"<<endl;	
}

istream & operator>>( istream & input, Circle & c){
	cout<<"Enter radius = ";
	input>>c.r;
	
	return input;
}

ostream & operator<<( ostream & output,const  Circle & c){
	output<<"The radius is = ";
	output<<c.r<<endl;
	
	output<<"The get Diameter of Circle is = ";
	output<<c.getDiameter()<<endl;
	
	output<<"The get Area of Circle is = ";
	output<<c.getArea()<<endl;
	
	output<<"The get Circumference of Circle is = ";
	output<<c.getCircumference()<<endl;
	
	return output;
}

class Rectangle:public Circle,public Point{
	
	int l,w;
	friend istream & operator>>(istream & input, Rectangle & r);
	friend ostream & operator<<(ostream & output,const  Rectangle & r);
	
	public:
		
		Rectangle();
		Rectangle(int);
		Rectangle(int,int);
		Rectangle(int,int,int,int,int);
		
	    Rectangle(const Rectangle &);
	    Rectangle(int ,int ,const Point & );
		Rectangle(int ,int ,const Circle & );
		~Rectangle();
		
		
		void setlength(int);
		void setwidth(int);
		void set(int,int);
		
		int getlength();
		int getwidth();
		
		int RectangleArea() const;
		
};

Rectangle::Rectangle():Point(),Circle(),l(3),w(2){
	cout<<"Default constructor of Rectangle is called"<<endl;
}

Rectangle::Rectangle(int ll):Point(),Circle(),l(ll),w(2){
	cout<<"1 Parameterized constructor of Rectangle is called"<<endl;
}

Rectangle::Rectangle(int ll,int ww):Point(),Circle(),l(ll),w(ww){
	cout<<"2 Parameterized constructor of Rectangle is called"<<endl;
}

Rectangle::Rectangle(int ll,int ww,int rr,int xx,int yy):Point(xx,yy),Circle(rr),l(ll),w(ww){
	cout<<"3 Parameterized constructor of Rectangle is called"<<endl;
}

Rectangle::Rectangle(const Rectangle & r):Point(r),Circle(r),l(r.l),w(r.w){
	cout<<"Copy constructor of Rectangle Point Circle  is called"<<endl;
}

Rectangle::Rectangle(int ll, int ww,const Point & p):Point(p),l(ll),w(ww){
	cout<<"Copy constructor of Rectangle Point  is called"<<endl;
}

Rectangle::Rectangle(int ll, int ww,const Circle & c):Circle(c),l(ll),w(ww){
	cout<<"Copy constructor of Rectangle Circle  is called"<<endl;
}

void Rectangle::setlength(int ll){
	l=ll;
}

void Rectangle::setwidth(int ww){
	w=ww;
}

void Rectangle::set(int ll,int ww){
	l=ll;
	w=ww;
}

int Rectangle::getlength(){
	return l;
}

int Rectangle::getwidth(){
	return w;
}

int Rectangle:: RectangleArea() const{
		return (l*w);
	}
	
Rectangle::~Rectangle() {
	cout<<"Destructor of Rectangle is called"<<endl;
}

istream & operator>>(istream & input, Rectangle & r){
	cout<<endl<<endl;
	cout<<"************** INPUT *********************"<<endl;
	cout<<endl<<endl;
	
	cout<<"Enter value of length = " ;
	input>>r.l;
	
	cout<<"Enter value of width = " ;
	input>>r.w;
	
	cout<<endl<<endl;
	
	cout<<"Enter members of Circle"<<endl;
	input>>(Point&)r;
	
	cout<<endl<<endl;
	
	cout<<"Enter members of Circle"<<endl;
	input>>(Circle&)r;
	
	return input;
}

ostream & operator<<(ostream & output,const  Rectangle & r){
	cout<<endl<<endl;
	cout<<"************** OUTPUT *********************"<<endl;
	cout<<endl<<endl;
	
	output<<"the value of length = " ;
	output<<r.l<<endl;
	
	output<<"the value of width = " ;
	output<<r.w<<endl;
	
	output<<"the Area of Rectangle = " ;
	output<<r.RectangleArea()<<endl;
	
	cout<<endl<<endl;
	
	output<<"The members of Point is"<<endl;
	output<<(Point&)r;
	cout<<endl<<endl;
	
	output<<"The members of Circle is"<<endl;
	output<<(Circle&)r;
	cout<<endl<<endl;
	
	return output;
}

int main(){
	
	Rectangle r(2,4,6,7,9);
	cout<<r;
		 
}
