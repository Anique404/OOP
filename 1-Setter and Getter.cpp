#include<iostream>
using namespace std;
class Rectangle{
	private:
		double length,width;
		public :
		    void setlength(double l){
				length=l>0?l:1;
			}
			void setwidth(double w){
				width=w>0?w:2;
			}
			void set(double l,double w){
				length=l>0?l:1;
				width=w>0?w:2;
			}
		   double getlength(){
				return length;
			}
		   double  getwidth(){
				return width;
			}
		
	     	double  getPerimeter(){
				return  2*(length*width);
			}
			
			double  getArea(){
				return length*width;
			}
		
};
int main(){
	Rectangle r1,r2;
	
	r1.set(2.5,3.9);
	r2.setlength(0);
	r2.setwidth(-1);
	
	cout<<"the length of R1=";
	cout<<r1.getlength();
	cout<<endl;
	
	cout<<"the width of R1=";
	cout<<r1.getwidth();
	cout<<endl;
	
	cout<<"the Perimeter of R1=";
	cout<<r1.getPerimeter();
	cout<<endl;
	
	cout<<"the Area of R1=";
	cout<<r1.getArea();
	cout<<endl;
	
	
	
	cout<<"the length of R2=";
	cout<<r2.getlength();
	cout<<endl;
	
	cout<<"the width of R2=";
	cout<<r2.getwidth();
	cout<<endl;
	
	cout<<"the Perimeter of R2=";
	cout<<r2.getPerimeter();
	cout<<endl;
	
	cout<<"the Area of R2=";
	cout<<r2.getArea();
	cout<<endl;
	
	
}
