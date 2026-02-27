#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char *argv[]){
//	ifstream in("text.txt");
if(!in){
//		cout<<"can't open";
		//exit(1);
	}
	char str[255];
	while(in){
		in.getline(str,255);
		cout<<str<<endl;
	}
	in.close();
}
