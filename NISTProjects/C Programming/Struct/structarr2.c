#include<stdio.h>
int main(void)
{
typedef struct
 {
  char name[50];
  int RollNum;
  float Marks;

 }STUDENT;
 int i;
 STUDENT nistians[3]={{"Brajesh Kumar",416,0},{"anshuman padhi",320,230},
                                      {"Gourav Babu",234,-50}};


for (i=0;i<3;i++)
{
 printf("Name of student %d %s\n",i,nistians[i].name);
}
 getch();
 return 0;
}
