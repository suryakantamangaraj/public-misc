#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct Sparse
{
    int row;//row number of non-zero element
    int col;//column number of non-zero element
    int val;//value number of non-zero element
    struct Sparse *next;
}Sparse;

Sparse* create(Sparse *sp)
{
    Sparse *nw,*p=sp;
    int mat[MAX][MAX],r,c,i,j,cnt;
    printf("Enter the dimension of the matrix>>");
    scanf("%d %d",&r,&c);
    printf("Enter the elements of the matrix\n");
    printf("********************************\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        {
            printf("Enter the element [%d][%d]>>",i,j);
            scanf("%d",&mat[i][j]);
        }
    printf("Elements of the matix:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d\t",mat[i][j]);
        printf("\n");
    }
    for(i=0,cnt=0;i<r;i++)
        for(j=0;j<c;j++)
            if(mat[i][j]!=0)
            {
                cnt++;
                nw=(Sparse*)malloc(sizeof(Sparse));
                nw->row=i;
                nw->col=j;
                nw->val=mat[i][j];
                nw->next=NULL;
                if(sp==NULL)
                    sp=nw;
                else
                    p->next=nw;
                p=nw;
            }
    if(cnt!=0)
    {
        nw=(Sparse*)malloc(sizeof(Sparse));
        nw->row=r;
        nw->col=c;
        nw->val=cnt;
        nw->next=sp;
        sp=nw;
    }
    return sp;
}
void display(Sparse *sp)
{
    Sparse *p;
    if(sp==NULL)
        printf("No non-zero elements are available.\n");
    else
    {
        printf("The Elements of Sparse Matrix are:\n\n");
        printf("Elements of the sparse matix:\n");
        for(p=sp;p;p=p->next)
             printf("%d\t%d\t%d\n",p->row,p->col,p->val);
    }
    return;
}     
int main()
{
      Sparse *sp=NULL;
      sp=create(sp);
      display(sp);
      system("PAUSE");
      return 0;
}
