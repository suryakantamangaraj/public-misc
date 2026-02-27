#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *infile,*outfile;
    int c,i,roll,marks;


    if((infile = fopen("c:\\test.txt","r"))==NULL)
        {
        printf("\n  \aERROR : could not open infile ");
        getch();
        exit(EXIT_FAILURE);
        }

    if((outfile = fopen("c:\\out.txt","w"))==NULL)
        {
        printf("\n  \aERROR : could not open outfile");
        getch();
        exit(EXIT_FAILURE);
        }
   for(i=0;i<4;i++)
{
    fscanf(infile,"%d\t%d",&roll,&marks);
    if (i==3)  marks=90;
    else marks+=5;
     fprintf(outfile,"%d\t%d\n",roll,marks);

}
   /* while((c=fgetc(infile)) != '\n')putchar(c); */
    getch();
    fclose(infile);
fclose(outfile);
    return 0;
}

