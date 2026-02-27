#include<stdio.h>
int main(void)
{
 int (*arrayptr)[10];
 int x[10]= {1,2,3};
arrayptr = x[0];
printf("%d", *arrayptr);
 getchar();
 return 0;
}
