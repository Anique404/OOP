#include<iostream>
#include<string>
using namespace std;
int dev(int n,int m);
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
	
	catch(int n){
		
		cout<<"Numenator can't be zero"<<endl;
	}
	catch(char const * d){
		cout<<d<<endl;
	}
	
	catch(...){
		cout<<"ERROR!";
	}
	
	
}

int dev(int n,int d){
	
	if (n==0)
	throw 404;
	if(d==0)
	throw "Denominator can't be zero";
	
	return n/d;
}
