#include<iostream>
#include<string>
using namespace std;


class devbyzero{
	int index;
	public:
		devbyzero():index(0){
			
		}
		void what()const {  // In this situation constant very important
			cout<<"ERROR!";
		}
};


int main(){
	int array[10]={1,2,3,4,5,6,7,8,9};
	int i;
	
	try{
	cout<<"Enter index=";
	cin>>i;

	if(i<0 || i>9)
	throw devbyzero();
	
	cout<<"The index is = "<<i;
	}
	
    catch(const devbyzero& d){
		d.what();
	}
	
	
}


