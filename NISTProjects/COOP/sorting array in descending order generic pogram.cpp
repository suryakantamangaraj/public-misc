#include<iostream>
using namespace std;
template <class s>
void b_sort(s u[],int k){
	for(int x=0;x<k-1;x++)
	for(int y=k-1;x<y;y--)
	if(u[y]>u[y-1]){
		s p;
		p=u[y];
		u[y]=u[y-1];
		u[y-1]=p;
	}
}
int main(){
	int i[5]={4,5,6,-2,1};
	float f[5]={5.4,4.7,6.8,3.4,1.2};
	b_sort(i,5);
	b_sort(f,5);
	int x=0,y=0;
	cout<<"integer array in descending order"<<endl;
	while(x<5)cout<<i[x++]<<"";
	cout<<"float array in descending order"<<endl;
	while(y<5)cout<<f[y++]<<"";
	return 0;
}
