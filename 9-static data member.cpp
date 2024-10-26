#include<iostream>
using namespace std;
class test{
	static int count;
	public:
		test(){
			count++;
			++count;
		}
		void show(){
			cout<<"the value of count is ="<<count<<endl;
		}
};
int test :: count=0;
int main(){
	test a;
	a.show();
	test b,c;
	b.show();
	test d,e,f;
	f.show();
	
}
