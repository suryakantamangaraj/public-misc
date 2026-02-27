#include<iostream>
using namespace std;
int main(){
	int s[]={2.7,3.5,4,6.2,5},*p=s,*q=s;
	for(int j=0;j<5;j++)
	{
		cout<<*q<<endl;
		++q;
	}
	for(int j=0;j<5;j++){
		
		cout<<*s<<endl;
		++p;
	}
	return 0;
}

