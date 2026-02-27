#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *infile;
    int count,i,station;
    float temp;
    char header[100];
    if((infile = fopen("c:\\temp.txt","r"))==NULL)
        {
        printf("\n  \aERROR : could not open infile ");
        getch();
        exit(EXIT_FAILURE);
        }
fgets(header,100,infile);
printf("%s",header);
fscanf(infile,"%d",&count);
for(i=0;i<count;i++)
{
    fscanf(infile,"%d, %f",&station,&temp);

    printf("%d\t%f\n",station,temp);

}

/*do {
    fscanf(infile,"%d, %f",&station,&temp);
    if(station!=-1)
    printf("%d\t%f\n",station,temp);

}while (station!=-1); */
/* while(!feof(infile))
 {
    fscanf(infile,"%d, %f",&station,&temp);
    printf("%d\t%f\n",station,temp);
 }*/

    getch();
    fclose(infile);

    return 0;
}

