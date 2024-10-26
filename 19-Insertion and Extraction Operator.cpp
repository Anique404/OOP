#include<iostream>
using namespace std;
class weight{
	int kg;
	friend istream & operator >>(istream& input,weight & x);
	friend ostream & operator <<(ostream& output,weight & x);
	public:
		weight(){
			kg=0;
		}
	};
istream & operator >>(istream& input,weight & x){
	input>>x.kg;
	return input;
}
ostream & operator <<(ostream& output,weight & x){
	output<<x.kg;
	return output;
}	
int main(){
	weight obj;
	cout<<"Enter weight = ";
	cin>>obj;
	cout<<"The weight is :";
	cout<<obj;
	
}
