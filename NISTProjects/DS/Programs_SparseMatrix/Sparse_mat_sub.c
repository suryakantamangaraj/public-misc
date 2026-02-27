#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
      int mat1[MAX][MAX],mat2[MAX][MAX],sp1[MAX][3],sp2[MAX][3],sp3[MAX][3];
      int i,j,r1,c1,r2,c2,k,m,n,res;
      printf("Enter the dimension of the 1st matrix>>");
      scanf("%d %d",&r1,&c1);
      printf("Enter the elements of the 1st matrix\n");
      printf("************************************\n");
      for(i=0;i<r1;i++)
          for(j=0;j<c1;j++)
          {
              printf("Enter the element [%d][%d]>>",i,j);
              scanf("%d",&mat1[i][j]);
          }
      printf("Elements of the 1st matix:\n");
      for(i=0;i<r1;i++)
      {
          for(j=0;j<c1;j++)
              printf("%d\t",mat1[i][j]);
          printf("\n");
      }
      printf("Enter the dimension of the 2nd matrix>>");
      scanf("%d %d",&r2,&c2);
      printf("Enter the elements of the 2nd matrix\n");
      printf("********************************\n");
      for(i=0;i<r2;i++)
          for(j=0;j<c2;j++)
          {
              printf("Enter the element [%d][%d]>>",i,j);
              scanf("%d",&mat2[i][j]);
          }
      printf("Elements of the 2nd matix:\n");
      for(i=0;i<r2;i++)
      {
          for(j=0;j<c2;j++)
              printf("%d\t",mat2[i][j]);
          printf("\n");
      }
      k=1;
      for(i=0;i<r1;i++)
          for(j=0;j<c1;j++)
          {
              if(mat1[i][j]!=0)
              {
                  sp1[k][0]=i;
                  sp1[k][1]=j;
                  sp1[k][2]=mat1[i][j];
                  k++;
              }
          }
      sp1[0][0]=r1;
      sp1[0][1]=c1;
      sp1[0][2]=k-1;
      printf("Elements of the 1st sparse matix:\n");
      for(i=0;i<=sp1[0][2];i++)
      {
          for(j=0;j<3;j++)
              printf("%d\t",sp1[i][j]);
          printf("\n");
      }
      k=1;
      for(i=0;i<r2;i++)
          for(j=0;j<c2;j++)
          {
              if(mat2[i][j]!=0)
              {
                  sp2[k][0]=i;
                  sp2[k][1]=j;
                  sp2[k][2]=mat2[i][j];
                  k++;
              }
          }
      sp2[0][0]=r2;
      sp2[0][1]=c2;
      sp2[0][2]=k-1;
      printf("Elements of the 2nd sparse matix:\n");
      for(i=0;i<=sp2[0][2];i++)
      {
          for(j=0;j<3;j++)
              printf("%d\t",sp2[i][j]);
          printf("\n");
      }
      if(sp1[0][0]!=sp2[0][0] || sp1[0][1]!=sp2[0][1])
         printf("\a\aMatrix subtraction is impossible.\n");
      else
      {
          i=1;j=1;k=1;m=sp1[0][2];n=sp2[0][2];
          while(i<=m && j<=n)
          {
             if(sp1[i][0]==sp2[j][0] && sp1[i][1]==sp2[j][1])
             {
                res=sp1[i][2]-sp2[j][2];
                if(res!=0)
                {
                    sp3[k][0]=sp1[i][0];
                    sp3[k][1]=sp1[i][1];
                    sp3[k][2]=res;
                    k++;
                }
                i++;j++;
             }
             else if(sp1[i][0]==sp2[j][0] && sp1[i][1]<sp2[j][1])
             {
                 sp3[k][0]=sp1[i][0];
                 sp3[k][1]=sp1[i][1];
                 sp3[k][2]=sp1[i][2];
                 i++;k++;
             }
             else if(sp1[i][0]==sp2[j][0] && sp1[i][1]>sp2[j][1])
             {
                 sp3[k][0]=sp2[j][0];
                 sp3[k][1]=sp2[j][1];
                 sp3[k][2]=-1*sp2[j][2];
                 j++;k++;
             }
             else if(sp1[i][0]<sp2[j][0])
             {
                 sp3[k][0]=sp1[i][0];
                 sp3[k][1]=sp1[i][1];
                 sp3[k][2]=sp1[i][2];
                 i++;k++;
             }
             else
             {
                 sp3[k][0]=sp2[j][0];
                 sp3[k][1]=sp2[j][1];
                 sp3[k][2]=-1*sp2[j][2];
                 j++;k++;
             }
          }
          while(i<=m)
          {
               sp3[k][0]=sp1[i][0];
               sp3[k][1]=sp1[i][1];
               sp3[k][2]=sp1[i][2];
               i++;k++;
          }
          while(j<=n)
          {
               sp3[k][0]=sp2[j][0];
               sp3[k][1]=sp2[j][1];
               sp3[k][2]=-1*sp2[j][2];
               j++;k++;
          }
          sp3[0][0]=sp1[0][0];
          sp3[0][1]=sp2[0][1];
          sp3[0][2]=k-1;
      }
      printf("Elements of the resultant sparse matix:\n");
      for(i=0;i<k;i++)
      {
          for(j=0;j<3;j++)
              printf("%d\t",sp3[i][j]);
          printf("\n");
      }
    
      system("PAUSE");
      return 0;
}
