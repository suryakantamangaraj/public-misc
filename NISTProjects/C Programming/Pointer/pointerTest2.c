#include<stdio.h>
int main(void)
{
 int *ip;
 ip = (int *) 0xEA123F;
 *ip = 67;
 printf("%d",*ip);
 getch();
 }

