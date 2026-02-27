#include<stdio.h>
int main(void)
{
 int x=5, y = 6;
 int *xptr, *yptr;

 xptr =  &x;
 yptr =  &y;
 printf("xptr = %p\n", xptr);
 printf("yptr = %p\n", yptr);

 xptr = yptr;

 //printf(5, "After Assignment");
 printf("xptr = %p\n", xptr);
 printf("yptr = %p\n", yptr);

 xptr ++;
 printf("xptr = %p\n", xptr);


 getch();
 return 0;
}
