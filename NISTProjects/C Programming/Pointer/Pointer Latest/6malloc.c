#include<stdio.h>
int main(void)
{
 int num,i,sum=0;
 int * array;
 printf("Enter the number of element you want to enter: ");
 scanf("%d",&num);

  for(i=0;i<num;i++)
  {
   printf("Enter Number for index %d :", i);
   scanf("%d",array+i);
  }

  for(i=0;i<num;i++)
    sum = sum + *(array+i);

  printf("The sum of the given numbers is: %d",sum);

 getch();
 return 0;
}
