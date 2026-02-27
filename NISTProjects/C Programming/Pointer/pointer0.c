#include<stdio.h>
int main(void)
{
 int x,*xptr;
 xptr=&x;
 printf("Enter the value for x:");
 scanf("%d",xptr);

 printf("\nContent of x is %d",x);
 printf("\nAddress of x is %p",&x);
 printf("\nxptr points to %p",xptr);
 printf("\nAddress of xptr is %p",&xptr);
 printf("\nAceessing x through xptr : %d",*xptr);
 getch();
 return 0;
}
