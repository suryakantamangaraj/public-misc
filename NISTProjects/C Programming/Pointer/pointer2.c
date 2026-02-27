#include<stdio.h>
int main(void)
{   int x=10,*xptr;
    float y=12.5,*yptr;
    xptr = &y;
    yptr = &x;
    printf("%d",*xptr);
    printf("\n%f",*yptr);


 getch();
 return 0;
}
