#include<iostream>
using namespace std;
class base{
	int n;
	public:
		 void input(){
		 	cout<<"enter an integer"<<endl;
		 	cin>>n;
		 }
		void print(){
			cout<<"the integer value is"<<n<<endl;
		}
};
class derived :public base{
	float m;
	public:
		 void input(){
		 		cout<<"enter an floating value"<<endl;
		 	cin>>m;
		 }
		void print(){
			cout<<"the floating  value is"<<m<<endl;
		}
};
int main(){
	base b,*p;
	derived d,*q;
	p=&b;
	p->input();
	p->print();
	q=&d;
	q->input();
	q->print();
	return 0;
}
