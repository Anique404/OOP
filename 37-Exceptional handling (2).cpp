#include<iostream>
#include<string>
using namespace std;
int dev(int n,int m);

class devbyzero{
	
	public:
		void what() {
			cout<<"Denominator can't be zero";
		}
};

int main(){
	int num,dem;
	
	try{
	cout<<"Enter numenator=";
	cin>>num;
	cout<<"Enter denomenator=";
	cin>>dem;
	
	int result=dev(num,dem);
	cout<<"The result is (n/d) ="<< result<<endl;	
	
	}
	

	catch(const devbyzero& d){
		d.what();
	}
	
	return 0;
	
}

int dev(int n,int d){
	
	if(d==0)
	throw devbyzero();
	
	return n/d;
}
