#include<iostream>
using namespace std;
class use{
	char *c;
	public:
		use(*x);
		{
			cout<<"\n"<<c;
		}
};
int main(){
	use c("hello world");
	return 0;
}
