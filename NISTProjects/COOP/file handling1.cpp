#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cout<<"enter 2 nos."<<endl;
	cin>>a>>b;
	a=a-b;
try{if (a==1)
throw a;
else
	c=b/a;
	cout<<c;
}
catch(int i){
	cout<<"exception caught"<<i<<endl;
}

int d=a*b;
	cout<<d;	
	return 0;
}
