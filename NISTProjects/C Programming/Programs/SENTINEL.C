/*============================== SENTINEL.C ==============================
  Using sentinel values to indicate end of input in a file
  ========================================================================*/
#include <stdio.h>
#include <stdlib.h>

int main(void)              
{
    FILE* statfile;
    int statnum, k;
    double temp;
    double mintemp,maxtemp, avgtemp, sumtemp;
    char header[100], filename[30];

    printf("Enter name of temperature data file >> ");
    gets(filename);
    if( (statfile=fopen(filename,"r"))==NULL)
        {
        getchar();
        printf("ERROR: could not open %s",filename);
        exit(1);
        }
/* read and echo the data from the file*/
    fgets(header,30,statfile);
    printf("\n\n%s\n",header);
    fscanf(statfile,"%d,%lg",&statnum, &temp);
    k=0;
    printf("%d  %d  %lg\n",k,statnum,temp);
    mintemp=maxtemp=sumtemp=temp;
    while(1)
        {
        fscanf(statfile,"%d,%lg",&statnum, &temp);
        if(statnum < 0) break;
        k++;
        printf("%d  %d  %lg\n",k,statnum,temp);
        sumtemp += temp;
        if(temp < mintemp) mintemp = temp;
        if(temp > maxtemp) maxtemp = temp;
        }
    avgtemp = sumtemp/(k+1);
    printf("Number of data points is %d\n",k+1);
    printf("Minimum temperature is %lg\n",mintemp);
    printf("Maximum temperature is %lg\n",maxtemp);
    printf("Average temperature is %lg\n",avgtemp);
    getchar();
    return 0;
}
