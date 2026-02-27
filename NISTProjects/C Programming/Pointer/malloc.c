#include<stdio.h>
int main(void)
{
 int count;
 int *x,i;
 printf("Enter How Many integer you want to enter: ");
 scanf("%d",&count);
 x= (int *) calloc(count * sizeof(int));
 for (i=0;i<count;i++)
 {
  printf("Enter value for index %d:",i);
  scanf("%d",x+i);
 }

 for (i=0;i<count;i++)
 {
  printf(" \nvalue in index %d is %d",i,*(x+i));

 }
 getch();
 return 0;
}
