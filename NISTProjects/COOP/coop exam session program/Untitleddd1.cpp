#include<iostream>
using namespace std;
int main(){
	int a=2,b=4;
int	&c=a;
	a=b;
	cout<<a<<endl<<b<<endl<<c<<endl;
	return 0;
}
