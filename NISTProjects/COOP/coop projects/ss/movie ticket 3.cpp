#include<iostream>
 using namespace std;

 char seats[5][8];

void roomMovie()
{
    int i,j;
    for ( i=0;i<5; i++)
        cout<<"|_ row n "<<i+1<<" _"<<seats[i][0]<<"_|"<<"_"<<seats[i][1]<<"_|"<<"_"<<seats[i][2]<<"_|"<<"_"<<seats[i][3]<<"_|"<<"_"<<seats[i][4]<<"_|"<<"_"<<seats[i][5]<<"_|"<<"_"<<seats[i][6]<<"_|"<<"_"<<seats[i][7]<<"_|"<<'\n';
        cout<<" input choice position ( row and column )"<<endl;
        cin>>i>>j;
        if (seats[i][j] != '1')
            seats[i][j] = '1';
        else
            {
                cout<<endl;
                cout<<" Warning : position not free. seek another."<<endl;
                cout<<endl;
            }
    for ( i=0;i<5; i++)
        cout<<"|_ row n "<<i+1<<" _"<<seats[i][0]<<"_|"<<"_"<<seats[i][1]<<"_|"<<"_"<<seats[i][2]<<"_|"<<"_"<<seats[i][3]<<"_|"<<"_"<<seats[i][4]<<"_|"<<"_"<<seats[i][5]<<"_|"<<"_"<<seats[i][6]<<"_|"<<"_"<<seats[i][7]<<"_|"<<'\n';
}

 int main()
 {
     for (int i=0; i<5; i++)
        for (int j=0; j<8; j++)
            seats[i][j] = 'O';
     bool choice = 1;
while (choice==true)
    {
     roomMovie();
     cout<< "Would like to choose another seat?(Please choose only 1 or 0)" <<endl;
     cout<< "(1) Yes" <<endl;
     cout<< "(0) No" <<endl;
     cin>>choice;
     if (choice==0)
        break;
    }
   return 0;
 }


