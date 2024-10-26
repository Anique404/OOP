#include<iostream>
using namespace std;
class test{
    
	public:
		static int count;
		static void show(){
			cout<<"the value of count is ="<<++count<<endl;
			cout<<"the value of count is ="<<count++<<endl;
		}
};
int test :: count=5;
int main(){
	test ::show();
	test ::show();

	
}
