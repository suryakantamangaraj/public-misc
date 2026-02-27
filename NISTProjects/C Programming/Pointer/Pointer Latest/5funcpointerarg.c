#include<stdio.h>
int add(int,int);
int sub(int,int);
void executeme(int (*fpt)(int,int));
int main(void)
{
 int (*fptr)(int,int);
int x,y,choice,result;
 printf("\nPlease Enater value for x:");
 scanf("%d",&x);
 printf("\nPlease Enater value for y:");
 scanf("%d",&y);
 printf("\nEnter 1 to add the numbers and 2 to substract: ");
 scanf("%d",&choice);
 if (choice==1)
    fptr= add;
 else if (choice==2)
    fptr = sub;
 else
 {
  printf("\nWrong code Entered");
  getch();
  exit(0);
 }
 executeme(fptr(x,y));

 getch();
 return 0;
}
void executeme(int (*ptr)(int,int))
{
 printf("Result is :%d",ptr);
}

int add(int x,int y)
{
 return x+y;
}
int sub(int x,int y)
{
 return x-y;
}
