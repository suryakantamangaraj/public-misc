#include<stdio.h>
int main(void)
{
 int i,j,k,sum;
 int matrix1[3][4]={{1,2,3,4},{2,3,4,5},{3,4,5,6}};
 int matrix2[4][2]={{1,2},{2,3},{3,4},{4,5}};
 int matresult[3][2];
 for(i=0;i<3;i++)
   {
    for(j=0;j<2;j++)
      {
        sum=0;
       for (k=0;k<4;k++)
           {
            sum = sum +matrix1[i][k]*matrix2[k][j];
           }
        matresult[i][j] =  sum;
      }
   }
   for(i=0;i<3;i++)
   {
    for(j=0;j<2;j++)
      {
       printf("%d\t",matresult[i][j]);
      }
     printf("\n");
    }
 getch();
 return 0;
}
