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

    const MyArray & operator =(const MyArray & r){
    	if(this!=&r){
	
     	if(r.size!=0){
     		if(size!=0){
     			delete [] array;
			 }
			
			 size=r.size;
			 array=new int [size];
			 int index;
			 for(index=0;index<size;index++){
				array[index]=r.array[index];
     	}
     	
		 }
		 else{
		 	
		 	if(size!=0){
		 		delete []array;
		 		size=0;
		 		array=0;
			 }
		 }
		 	}
		 	
		 	return *this;
		 	
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
	
	MyArray a,b;
	
	int list [6]={1,3,2,4,7,8};
	MyArray c(5);
	MyArray d(list,6);
	
	cin>>a;
	c=d;
	cout<<"Elements of c from d"<<endl;
	cout<<c;
	c=a;
	cout<<"Elements of c from a"<<endl;
	cout<<c;
	a=b;
	cout<<"Elements of a from b"<<endl;
	cout<<a;
	a=c;
	cout<<"Elements of a from c"<<endl;
	cout<<a;
	d=d;
	cout<<"Elements of d from d"<<endl;
	cout<<d;
	
}
