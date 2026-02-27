#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    FILE *infile, *outfile;
    int c;
    char filename[50];
    printf("\n Program to convert contents of file to UPPERCASE");
    printf("\nEnter input file name >> ");
    gets(filename);
    if((infile = fopen(filename,"r"))==NULL)
        {
        printf("\n\aERROR : could not open file %s",filename);
        exit(EXIT_FAILURE);
        }
    printf("\n\nEnter output file name >> ");
    gets(filename);
    if((outfile = fopen(filename,"r"))==NULL)
        {
        printf("\n\aERROR : could not open file %s",filename);
        system("PAUSE");
        exit(EXIT_FAILURE);
        }
    while((c=fgetc(infile)) != EOF)fputc(toupper(c),outfile);
    fclose(infile);
    fclose(outfile);
    getchar();
    return 0;
}
