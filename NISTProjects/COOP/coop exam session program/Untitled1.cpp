#include<iostream>
using namespace std;
int main(){
	int a,b,c,n,i;
	a=0;b=1;
	cout<<"enter no. to show"<<endl;
	cin>>n;
	for(i=0;i<=n;i++){
		c=a+b;
		cout<<" \t"<<c;
		a=b;
		b=c;
	}
	return 0;
}
