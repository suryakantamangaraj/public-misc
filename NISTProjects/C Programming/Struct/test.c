#include<stdio.h>
int main(void)
{
   union u_foo
		{
		float xval;
		long num;
		char name[20];
		} foobar;
 foobar.xval=64;
 /*foobar.num=100;  */
 printf("%f",foobar.num);
 getch();
 return 0;
}
