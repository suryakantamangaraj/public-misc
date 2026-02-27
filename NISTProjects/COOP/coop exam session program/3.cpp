#include<iostream>
using namespace std;
struct s;
{
	int x;
	s(int k)
	{
		x=k;
	}
	void operator++()
	{
		++x;
	}
}
int main(){
	s b(2);
	b++;
	cout<<b.x;
	return 0;
}
