#include<stdio.h>
int main(void)
{  int i=0;
   char country[5][30]={"india","pakistan","srilanka","nepal"};
   char capital[5][30]={"NewDelhi","Islamabad","Colombo","Kathmandu"};
   char inpstr[50];
   printf("Please enter the country name:");
   while((inpstr[i]=getchar())!='\n')
   {
    if ((inpstr[i]>64) && (inpstr[i]<92))
       inpstr[i]=inpstr[i]+32;
      ++i;
   }
   inpstr[i]='\0';

   for (i=0;i<4;i++)
       {
        if (strcmp(inpstr,country[i])==0)
        {
           printf("Name of the capital is:%s",capital[i]);
           break;
        }
       }
       if (i==4)
       printf("Country name is not in the database");

 getch();
 return 0;
}
