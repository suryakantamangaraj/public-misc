/*============================== TYPEIT.C ==============================
  Program writes the contents of a file to the standard output.
  ======================================================================*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *infile;
    int c;
    char filename[50];
    printf("\nEnter file name to display >> ");
    gets(filename);
    if((infile = fopen(filename,"r"))==NULL)
        {
        printf("\n  \aERROR : could not open file %s",filename);
        exit(EXIT_FAILURE);
        }
    while((c=fgetc(infile)) != EOF)putchar(c);
    fclose(infile);
    return 0;
}
