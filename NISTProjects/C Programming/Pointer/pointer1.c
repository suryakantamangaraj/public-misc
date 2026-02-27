#include<stdio.h>
int main(void)
{
 int x=5;
 void *y;
 y =  &x;
 printf("%p\n", y);
 printf("%d\n", y);
 printf("%d",*((int *)y));
 getch();
 return 0;
}
