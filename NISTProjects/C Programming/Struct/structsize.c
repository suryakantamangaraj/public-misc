#include<stdio.h>
int main(void)
{
 struct student
 {
  float Marks;
  int RollNum;
  char name[50];
 }Nitesh,Sourav;

struct hello{

 int x;
 float z;
 char c;
 };
 printf("%d",sizeof(struct hello));


printf("Size of name: %d \nSize of RollNum:%d \n Size of marks:%d \n Size of student: %d",
              sizeof(Nitesh.name),sizeof(Nitesh.RollNum),sizeof(Nitesh.Marks),sizeof(struct student));

 getch();
 return 0;
}
