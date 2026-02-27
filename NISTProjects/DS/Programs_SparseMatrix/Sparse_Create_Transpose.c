#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
      int mat[MAX][MAX],sp[MAX][3],tm[MAX][3];
      int i,j,r,c,k;
      printf("Enter the dimension of the matrix>>");
      scanf("%d %d",&r,&c);      
      printf("********************************\n");
      printf("Enter the elements of the matrix\n");
      for(i=0;i<r;i++)
          for(j=0;j<c;j++)
          {
              printf("\n\nEnter the element [%d][%d]>>",i,j);
              scanf("%d",&mat[i][j]);
          }
      printf("Elements of the matix:\n");
      for(i=0;i<r;i++)
      {
          for(j=0;j<c;j++)
              printf("%d\t",mat[i][j]);
          printf("\n");
      }
      k=1;
      for(i=0;i<r;i++)
          for(j=0;j<c;j++)
              if(mat[i][j]!=0)
              {
                  sp[k][0]=i;
                  sp[k][1]=j;
                  sp[k][2]=mat[i][j];
                  k++;
              }
      sp[0][0]=r;
      sp[0][1]=c;
      sp[0][2]=k-1;
      printf("Elements of the sparse matix:\n");
      for(i=0;i<=sp[0][2];i++)
      {
          for(j=0;j<3;j++)
              printf("%d\t",sp[i][j]);
          printf("\n");
      }
      tm[0][0]=sp[0][1];
      tm[0][1]=sp[0][0];
      tm[0][2]=sp[0][2];
      k=1;
      for(i=0;i<sp[0][1];i++)
          for(j=1;j<=sp[0][2];j++)
              if(sp[j][1]==i)
              {
                  tm[k][0]=sp[j][1];
                  tm[k][1]=sp[j][0];
                  tm[k][2]=sp[j][2];
                  k++;
              }
      printf("Elements of the transpose matix:\n");
      for(i=0;i<=tm[0][2];i++)
      {
          for(j=0;j<3;j++)
              printf("%d\t",tm[i][j]);
          printf("\n");
      }
      system("PAUSE");
      return 0;
}
