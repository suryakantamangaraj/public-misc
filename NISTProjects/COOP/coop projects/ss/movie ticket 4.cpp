
#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
using namespace std;

//STRUCTURE
typedef struct{
        char showname[20];
        char date[12];
        char time[6];
        char gate[2];
}Show;
Show show={"Romeo and joliet","10-4-2010","20:30","7"};

typedef struct{
        char name[30];
        char booking_ID[3];
        int seats;
}Seat;
Seat choice[4][5];  

void displaymenu();
void booking();
void cancel();
void seat();
void ticket();
void records();
void looping();
void exit_();
        
//Variables
int selection;  
int i;
int j;
int seats_num[20]={0};
int booking_ID=100;
int seatsAvailable=20;


int main(void)
{
        displaymenu();
        while(selection!=5)
        {
                looping();
        }
        return 0;
}
                
        void displaymenu()
        {
        cout<<"\n";
        cout<<"\t Theater reservation\n"
                  "\t=======================\n"
                  "\t  MENU\n"
                  "\t=======================\n"
                  "\t1.BOOKING\n"
                  "\t2.CANCEL\n"
                  "\t3.SEAT\n"
                  "\t4.RECORDS\n"
                  "\t5.EXIT\n\n";

        cout<<"\tEnter your selection : ";
        cin>>selection;
        looping();
        return;
        }

        //looping()
        void looping()
        {       
        switch(selection)
                {
                case 1:
                        booking();
                        break;
                case 2: 
                        cancel();
                        break;        
                case 3:
                        seat();
                        break;
                case 4:
                        records();
                        break;
                case 5:
                        exit_();
                        break;
                default:
                cout<<"\tInvalid selecion.Try again\n";
        }
        return;
        }
        
        //booking       
        void booking()
        {
                for(i=0;i<4;i++)
                        for(j=0;j<5;j++)  
                {                       
                cout<<"\tPlease enter seats number   : ";
                cin>>choice[i][j].seats;
                fflush(stdin);

                if(choice[i][j].seats<=seatsAvailable)
                {
                cout<<"\tPlease enter customer name : ";
                cin>>choice[i][j].name;
                fflush(stdin);
                ticket();
                booking_ID++;
                        }
                seatsAvailable=seatsAvailable-choice[i][j].seats;
                
                system("pause");
                system("cls");
                displaymenu();  
                }
                if(seatsAvailable<0)
                {
                        cout<<"\n";
                        cout<<"\tSORRY, the show is fully booked\n";
                        cout<<"\t=================END=================\n\n";
                        displaymenu();
                }
                
                if(choice[i][j].seats>seatsAvailable)
                        {
                                cout<<"\n";
                                cout<<"\tThe show leave %d seats\n",seatsAvailable;
                                displaymenu();
                        }
        return;
        }
        
        void ticket()
        {
        cout<<"\n\n";
        
        cout<<"\t-----------------THEATER BOOKING TICKET----------------\n";
        cout<<"\t============================================================\n";
        cout<<"\t Booking ID : "<<booking_ID<<" \t\t\tShow Name : "<<show.showname<<endl;
        cout<<"\t Customer  : "<<choice[i][j].name<<endl;
        cout<<"\t\t\t                              Date      : "<<show.date<<endl;
        cout<<"\t                                              Time      : "<<show.time<<endl;
        cout<<"\t                                              Hall      : "<<show.gate<<endl;
        cout<<"\t                                              Seats No. : "<<i+1<<endl<<j+65<<endl;
        cout<<"\t============================================================\n";
        return;}

        
        // cancel
         void cancel()
         {
              char cancelcustomername[80];
              cout<<"Enter customer name to be cancel:";
              cin>>cancelcustomername;
              for(int i=0; i<4 ; i++)
              {
                      for (int j =0 ; j<5; j++)
                      {
                          if (strcmp(choice[i][j].name , cancelcustomername) == 0)
                          {
                                         //seats_num++;
                                         cout<<"Loop entered!\n";
                                         choice[i][j].seats = 1 ;
                                         system("pause");
                                         system("cls");
                                         displaymenu();
                                         return ;
                          }
                      }
              }
          }
        //seat
        void seat()
        {       
                cout<<"  A   B   C   D  E\n";
                for(j=0;j<5;j++)
                {
                cout<<booking_ID<<endl; 
                }
                for(i=0;i<4;i++)
                {
                        cout<<"\n";
                        cout<<i+1<<endl;
                }
                system("pause");
                system("cls");
                displaymenu();
        return;
        }

        void records()   //For Staff to View the Show's records
        {       
       
        
                cout<<"\t====================================\n";
                cout<<"\tALL SHOW RECORDS\n";  
                cout<<"\t====================================\n";
                cout<<"\tSeats Available left : "<<seatsAvailable<<endl;
                
               // ticket();
                system("pause");
                system("cls");
                displaymenu();
                      
        return;
        }

        void exit_()
        {
        cout<<"\tThank you for using this system\n";
        exit(1);
        return;
        }

