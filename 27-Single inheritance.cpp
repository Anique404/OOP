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
		
		int PointArea();
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

int Point::PointArea(){
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
	cout<<"Copy constructor of Circle is called"<<endl;
}

Circle::Circle(int rr,const Point & p):Point(p),r(rr){
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
	cout<<"Enter members of Point"<<endl;
	input>>(Point&)c;
}

ostream & operator<<( ostream & output,const  Circle & c){
	output<<"The radius is = ";
	output<<c.r<<endl;
	output<<"The members of Point is"<<endl;
	output<<(Point&)c;
}

int main(){
	
	Circle c,c1(3);
	cin>>c;
	cout<<c;
	cout<<c1;
		 
}
