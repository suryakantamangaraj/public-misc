#include<iostream>
void fn(){
	struct str{
		enum{false,true}bool;
	};
	const int true=13;
}
int main(){
	fn();
	return 0;
}
