#include<stdio.h>
int main(void)
{
void show(int [][3]);
int a[2][3] ={10,20,30,40,50,60};
show(a);
getch();
return 0;
}
void show (int a[][3])
{
int i,j;
for (i=0;i<2;i++)
 for (j=0;j<3;j++)
     printf("Values at a[%d][%d] is  %d \n",i,j,*(*(a+i)+j));
return;
}




