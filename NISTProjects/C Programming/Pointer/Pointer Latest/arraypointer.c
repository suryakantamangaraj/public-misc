#include<stdio.h>
int main(void)
{
 int (*arrayptr)[10];
 int x[10]= {1,2,3};
arrayptr = x;
printf("%d", *arrayptr);
 getchar();
 return 0;
}
