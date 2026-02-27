#include<iostream>
using namespace std;
class student{
	protected:
		int id,mark;
		public:
			student(){
				cout<<"enter id"<<endl;
				cin>>id;
				cout<<"enter marks"<<endl;
				cin>>mark;
			}
			void show(){
				cout<<"id:"<<id<<endl<<"marks:"<<mark<<endl;
			}
};
int main(){
	int n;
	cout<<"enter how much student's data you want to keep"<<endl;
	cin>>n;
	student *sptr,s[n];
	sptr=s;//or,sptr=&s[0];---->>give same result
		cout<<"data of students are"<<endl;
	for(int i=0;i<n;i++){
		sptr->show();
		sptr++;
	}
	return 0;
}
