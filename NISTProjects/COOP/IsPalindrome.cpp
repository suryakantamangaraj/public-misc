#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int IsPalindrome(char *A)
{	int i=0;
	std::stack<char> S;
	int l=strlen(A)/2;
	
	while(i!=l)
	{	S.push(A[i]);

		i++;
	}
	if(strlen(A)%2!=0)
		i++;	
	while(A[i])
	{	if(S.empty()||A[i]!=S.top())
		{	
			return 0;
		}	
		S.pop();
		i++;
	}
	return (S.empty());
}
int main()
{	char Word[100];
	cout<<"Enter your string:";
	cin>>Word;
	cout<<"Checking if the string is a Palindrome...\n";
	int x=IsPalindrome(Word);
	if(x)
		cout<<"It is a Palindrome.";
	else
		cout<<"It is not a Palindrome.";
	cout<<endl;
}
	
