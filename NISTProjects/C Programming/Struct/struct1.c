#include<stdio.h>
int main(void)
{
 struct student
 {
  char name[50];
  int RollNum;
  float Marks;

 }Nitesh,Sourav;

 struct student brajesh={"Brajesh Kumar",416,0},anshuman;

 anshuman=brajesh;
 printf("\n\n\nName:%s\nRollNum: %d\nMarks: %d"
                    ,anshuman.name,anshuman.RollNum,anshuman.Marks);

 getch();
 return 0;
}
