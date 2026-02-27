#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *infile, *oddfile, *evenfile;
    int n;

    if((infile = fopen("c:\\input.txt","r"))==NULL)
        {
        printf("\n  \aERROR : could not open file input.dat");
        getchar();
        exit(0);
        }

    if((oddfile = fopen("c:\\odd.txt","w"))==NULL)
        {
        printf("\n  \aERROR : could not open file odd.dat");
        getchar();
        exit(0);
        }

    if((evenfile = fopen("c:\\even.txt","w"))==NULL)
        {
        printf("\n  \aERROR : could not open file even.dat");
        getchar();
        exit(0);
        }

    while(!feof(infile))
        {
        fscanf(infile,"%d",&n);
        if(!feof(infile))
            {
            printf("  n = %d\n",n);
            if(n%2) fprintf(oddfile, "%d\n",n);
            else    fprintf(evenfile,"%d\n",n);
            }
        }
    return 0;
}
