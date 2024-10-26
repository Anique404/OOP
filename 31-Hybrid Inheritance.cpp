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

class Circle:public Point{
	int r;

	static const double pi;
	friend istream & operator>>(istream & input, Circle & c);
	friend ostream & operator<<(ostream & output,const  Circle & c);
	
	public:
		
		Circle();
		Circle(int);
		Circle(int,int,int);
		Circle(const Circle &);
		Circle(int r,const Point & p);
		~Circle();
		
		void setr(int);
		int getr();
		
		double getDiameter()const;
     	double getArea()const;
	    double getCircumference()const;
	
};

const double Circle:: pi = 3.14159;

Circle::Circle(): Point(),r(5){
	cout<<"Default constructor of Circle is called"<<endl;
}

Circle::Circle(int rr): Point(),r(rr){
	cout<<"1 Parmeterize constructor of Circle is called"<<endl;
}

Circle::Circle(int rr ,int xx, int yy): Point(xx,yy),r(rr){
	cout<<"3 Parmeterize constructor of Circle is called"<<endl;
}

Circle::Circle(const Circle & c):Point(c),r(c.r){
	cout<<"Copy constructor of Circle and point is called"<<endl;
}

Circle::Circle(int rr,const Point & p):Point(p),r(rr){
	cout<<"Copy constructor of Circle Point is called"<<endl;
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
	
	cout<<endl<<endl;
	
	cout<<"Enter members of Point"<<endl;
	input>>(Point&)c;
	
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
	
	cout<<endl<<endl;
	
	output<<"The members of Point is"<<endl;
	output<<(Point&)c;
	
	return output;
}

class Rectangle:public Point{
	
	int l,w;
	friend istream & operator>>(istream & input, Rectangle & r);
	friend ostream & operator<<(ostream & output,const  Rectangle & r);
	
	public:
		
		Rectangle();
		Rectangle(int);
		Rectangle(int,int);
		Rectangle(int,int,int,int);
		
	    Rectangle(const Rectangle &);
		Rectangle(int ,int ,const Point & );
		~Rectangle();
		
		
		void setlength(int);
		void setwidth(int);
		void set(int,int);
		
		int getlength();
		int getwidth();
		
		int RectangleArea() const;
		
};

Rectangle::Rectangle():Point(),l(3),w(2){
	cout<<"Default constructor of Rectangle is called"<<endl;
}

Rectangle::Rectangle(int ll):Point(),l(ll),w(2){
	cout<<"1 Parameterized constructor of Rectangle is called"<<endl;
}

Rectangle::Rectangle(int ll,int ww):Point(),l(ll),w(ww){
	cout<<"2 Parameterized constructor of Rectangle is called"<<endl;
}

Rectangle::Rectangle(int ll,int ww,int xx,int yy):Point(xx,yy),l(ll),w(ww){
	cout<<"4 Parameterized constructor of Rectangle is called"<<endl;
}

Rectangle::Rectangle(const Rectangle & r):Point(r),l(r.l),w(r.w){
	cout<<"Copy constructor of Rectangle and Point  is called"<<endl;
}

Rectangle::Rectangle(int ll, int ww,const Point & p):Point(p),l(ll),w(ww){
	cout<<"Copy constructor of Rectangle Point  is called"<<endl;
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
	
	cout<<"Enter value of length = " ;
	input>>r.l;
	
	cout<<"Enter value of width = " ;
	input>>r.w;
	
	cout<<endl<<endl;
	
	cout<<"Enter members of Point"<<endl;
	input>>(Point&)r;
	
	return input;
}

ostream & operator<<(ostream & output,const  Rectangle & r){

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
	
	return output;
}

class Triangle:public Circle,public Rectangle{
	
	int h,b;
	friend istream & operator>>(istream & input,  Triangle& t);
	friend ostream & operator<<(ostream & output,const  Triangle & t);
	
	public:
		
	    Triangle();
		Triangle(int);
		Triangle(int,int);
		Triangle(int,int,int,int,int);
		
	    Triangle(const Triangle &);
	    Triangle(int ,int ,const Rectangle & );
		Triangle(int ,int ,const Circle & );
		~Triangle();
		
		
		void setheight(int);
		void setbase(int);
		void set(int,int);
		
		int getheight();
		int getbase();
		
		double TriangleArea() const;
		
};

Triangle::Triangle():Rectangle(),Circle(),h(3),b(2){
	cout<<"Default constructor of Triangle is called"<<endl;
}

Triangle::Triangle(int hh):Rectangle(),Circle(),h(hh),b(2){
	cout<<"1 Parameterized constructor of Triangle is called"<<endl;
}

Triangle::Triangle(int hh,int bb):Rectangle(),Circle(),h(hh),b(bb){
	cout<<"2 Parameterized constructor of Triangle is called"<<endl;
}

Triangle::Triangle(int hh,int bb,int rr,int ll,int ww):Rectangle(ll,ww),Circle(rr),h(hh),b(bb){
	cout<<"3 Parameterized constructor of Triangle is called"<<endl;
}

Triangle::Triangle(const Triangle & t):Rectangle(t),Circle(t),h(t.h),b(t.b){
	cout<<"Copy constructor of Triangle Rectangle Circle is called"<<endl;
}

Triangle::Triangle(int hh, int bb,const Rectangle & r):Rectangle(r),h(hh),b(bb){
	cout<<"Copy constructor of Triangle Rectangle is called"<<endl;
}

Triangle::Triangle(int hh, int bb,const Circle & c):Circle(c),h(hh),b(bb){
	cout<<"Copy constructor of Triangle Circle  is called"<<endl;
}

void Triangle::setheight(int hh){
	h=hh;
}

void Triangle::setbase(int bb){
	b=bb;
}

void Triangle::set(int hh,int bb){
	h=hh;
	b=bb;
}

int Triangle::getheight(){
	return h;
}

int Triangle::getbase(){
	return b;
}

double Triangle:: TriangleArea() const{
	
		return (0.5*(h*b));
	}
	
Triangle::~Triangle() {
	cout<<"Destructor of Rectangle is called"<<endl;
}

istream & operator>>(istream & input, Triangle & t){
	cout<<endl<<endl;
	cout<<"************** INPUT *********************"<<endl;
	cout<<endl<<endl;
	
	cout<<"Enter value of Height = " ;
	input>>t.h;
	
	cout<<"Enter value of Base = " ;
	input>>t.b;
	
	cout<<endl<<endl;
	
	cout<<"Enter members of Rectangle"<<endl;
	input>>(Rectangle&)t;
	
	cout<<endl<<endl;
	
	cout<<"Enter members of Circle"<<endl;
	input>>(Circle&)t;
	
	return input;
}

ostream & operator<<(ostream & output,const  Triangle & t){
	cout<<endl<<endl;
	cout<<"************** OUTPUT *********************"<<endl;
	cout<<endl<<endl;
	
	output<<"the value of Height = " ;
	output<<t.h<<endl;
	
	output<<"the value of Base = " ;
	output<<t.b<<endl;
	
	output<<"the Area of Triangle = " ;
	output<<t.TriangleArea()<<endl;
	
	cout<<endl<<endl;
	
	output<<"The members of Rectangle is"<<endl;
	output<<(Rectangle&)t;
	cout<<endl<<endl;
	
	output<<"The members of Circle is"<<endl;
	output<<(Circle&)t;
	cout<<endl<<endl;
	
	return output;
}

int main(){
	
	Triangle t;
	cin>>t;
	cout<<t;
		 
}
