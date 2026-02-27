#include<stdio.h>

int main(void)
{
 int i;
 for(i=0;*("I am a pointer" + i)!='\0';++i)
 printf ("%c",*("I am a pointer" +i));
 getchar();
 return 0;
}
