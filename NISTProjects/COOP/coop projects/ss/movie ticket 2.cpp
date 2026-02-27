 #include<cstdlib>
#include<iostream>
#include<windows.h>
#include<iomanip>
#include<fstream>  
#include<string.h>

using namespace std;


int main() 

{
	int a;
	int b;
    char seats[5][40]=  {"A |_1_||_2_||_3_||_4_||_5_||_6_||_7_|",
                         "B |_1_||_2_||_3_||_4_||_5_||_6_||_7_|",
                         "C |_1_||_2_||_3_||_4_||_5_||_6_||_7_|",
                         "D |_1_||_2_||_3_||_4_||_5_||_6_||_7_|",
                         "E |_1_||_2_||_3_||_4_||_5_||_6_||_7_|"};
                      
    
    seats [a][b]='*';
    
	 for(a=0;a<5;a++)
             {
                     cout<<seats[a]<<endl<<endl;
             }
             
		cout<<endl;
		
	
	

	{
    
	char choice;
	cout<<"Would like to choose another seat?(Please choose only 1 or 2)"<<endl;
	cout<<"(1) Yes"<<endl;
	cout<<"(2) No"<<endl;
	cin>>choice;
	if(choice=='1')
	{	
		main();
    }
	if(choice=='2')
	{
		exit(0);
	}
	 

}
	return 0;
}
