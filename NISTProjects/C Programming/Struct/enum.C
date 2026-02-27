#include<stdio.h>
enum WEEKDAYS{SUN,MON,TUES,WED,THU,FRI,SAT};
int main(void)
{
  enum WEEKDAYS today, tomorrow ;
  today = MON;
  tomorrow = SAT;
  printf("today = %d and tomorrow = %d",today,tomorrow);
  today =64;
  printf("\n new value of today = %d",today);
  getch();
  return 0;
}
