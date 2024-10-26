#include<iostream>
using namespace std;
class MyArray{
	int size;
	int *array;
	friend istream &operator>>(istream &input, MyArray &s);
    friend ostream &operator<<(ostream &output, const MyArray &s);
	public:
		MyArray(){
			size=0;
			array=NULL;
		}
		MyArray(int value,int n=0){
			size=n>0?n:5;
			array=  new int [size];
			int index;
			for(index=0;index<size;index++){
				array[index]=value;
			}
		}
		MyArray(int*a , int n){
			
			size=n>0?n:5;
			array=  new int [size];
			int index;
			for(index=0;index<size;index++){
				array[index]=a[index];
			}
			
		}
		
		MyArray(const MyArray & a){
		if(a.size!=0){
	
			size=a.size;
			array=  new int [size];
			int index;
			for(index=0;index<size;index++){
				array[index]=a.array[index];
			}
		}
		else{
			size=0;
			array=NULL;
		}
		
			}
			
		
		~MyArray(){
			if(array!=NULL){
			
			delete [] array;
			array=NULL;
			
		}
}	
	
	
};


istream &operator>>(istream &input, MyArray &s){
	
	while(s.size<=0){
		cout<<"enter size = ";
		input >>s.size;
	}
	   s.array=  new int [s.size];
	   cout<<endl;
	for(int i=0;i<s.size;i++){
		cout<<"enter element "<<i+1<<" = ";
		input>>s.array[i];
	}
	return input;
}


ostream &operator<<(ostream &output, const MyArray &s){
	cout<<endl;
	for(int i=0;i<s.size;i++){
		output<<s.array[i]<<"  ";
	}
	cout<<endl;
	return output;
}


int main(){
	
	MyArray a;
	
	cin>>a;
	cout<<a;
	
	MyArray a2(3,4);

	cin>>a2;
	cout<<a2;
	
	int list[]={2,6,4,1,9,0,7,5,3,1};
	
	MyArray a3(list,7);
	cout<<a3;
	
	MyArray a4=a2;
	cout<<a4;
	
}
