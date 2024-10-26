#include<iostream>
using namespace std;
class weight{
	int kg;
	public:
		weight(){
			kg=0;
		}
		void print(){
			cout<<"weight is :"<<kg<<endl;
		}
		
//		void operator ++(){ // pre increament operator
//			++kg;
//		}
//		void operator ++(int){ // post increament operator
//			kg++;
//		}
//		void operator --(){ // pre increament operator
//			--kg;
//		}
//		void operator --(int){ // post increament operator
//			kg--;
//		}
		
		weight operator ++(){ // pre increament operator
			weight temp;
			temp.kg=++kg;
			return temp;
		}
		weight operator ++(int){ // post increament operator
			weight temp;
			temp.kg=kg++;
			return temp;
		}
		weight operator --(){ // pre increament operator
			weight temp;
			temp.kg=--kg;
			return temp;
		}
		weight operator --(int){ // post increament operator
			weight temp;
			temp.kg=kg--;
			return temp;
		}
};

int main(){
	weight obj,obj2;
	

	
//	++obj;
//	obj.print();
//	obj++;
//	obj.print();
//	
//	--obj;
//	obj.print();
//	obj--;
//	obj.print();


obj2=++obj;
obj2.print();

obj2=++obj;
obj2.print();
obj.print();

obj=++obj2;
obj.print();

obj=obj2++;
obj.print();

obj2=--obj;
obj2.print();

obj2=obj--;
obj2.print();

}
