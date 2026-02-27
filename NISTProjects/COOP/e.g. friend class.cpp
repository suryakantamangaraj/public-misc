#include<iostream>
using namespace std;
class a{
	int x;
	friend void display(a bj);
};
void display(a obj){
	cout<<"enter a no"<<endl;
	cin>>obj.x;
	cout<<"the no is"<<obj.x<<endl;
}
int main(){
	a obj;
	display(obj);
	return 0;
}
