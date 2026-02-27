#include <stdio.h>

struct point
   {
      float x,y;
   };
struct circle
   {
      float r;
      struct point o;
   };
float sqr(float x)
   {
      return x * x;
   }
int contains(struct circle c, struct point p)
   {
      return sqr(c.o.x - p.x) + sqr(c.o.y - p.y) <= sqr(c.r);
   }
int main(void)
  {
     struct circle mycircle = {2, {1, 1}};
     struct point mypoint = {2, 3};

     printf("The circle with centre (%f,%f)\n", mycircle.o.x, mycircle.o.y);
     printf("and radius %f\n", mycircle.r);
     if (contains(mycircle, mypoint))
        printf("contains ");
     else
        printf("does not contain ");
     printf("the point (%f,%f).\n", mypoint.x, mypoint.y);
     getch();
     return 0; 
  }
