#include<stdio.h>
int main(void)
{  int i;
   char *country[5]={"india","pakistan","srilanka","nepal"};
   char *capital[5]={"NewDelhi","Islamabad","Colombo","Kathmandu"};
   char inpstr[50];
   printf("Please enter the country name:");
   gets(inpstr);

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
