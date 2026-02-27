#include<stdio.h>
int main(void)
{  int x,i,j;
   char *strings[5]={"Dog","Cat","Donkey","Horse","Cow"};
   char *temp;

   for (i=0;i<4;++i)
       for(j=i+1;j<5;j++)
          {
             if(strcmp(strings[i],strings[j])>0)
             {
               temp = strings[i];
               strings[i]=strings[j];
               strings[j]=temp;
             }
          }
 printf("Strings in sorted order:\n\n");
 for(x=0;x<5;x++)
   {
     printf("string %d:",x);
     puts(strings[x]);
   }
 getch();
 return 0;
}
