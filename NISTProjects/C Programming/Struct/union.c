#include<stdio.h>
int main(void)
{
union test
{
   int x;
   char c;
} var1;
  var1.x=65;
  printf("x=%d,c=%c",var1.x,var1.c);

  var1.c=578;
  printf("\nx=%d,c=%c",var1.x,var1.c);
 getch();
 return 0;
}
