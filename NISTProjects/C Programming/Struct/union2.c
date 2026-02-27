
#include <stdio.h>
#define PI 3.14159265
#define CIRCLE 1
#define RECTANGLE 2

struct point
   {
      float x,y;
   };
struct circle
   {
      float r;        /* radius */
      struct point o; /* centre */
   };
struct rectangle
   {
      struct point tr; /* top right corner of rectangle */
      struct point bl; /* bottom left corner of rectangle */
   };
union shape
   {
      struct circle c;
      struct rectangle r;
   };
float area(union shape s, int which_shape)
  {
     switch (which_shape)
        {
           case CIRCLE:
              return PI * s.c.r * s.c.r;
           case RECTANGLE:
              return (s.r.tr.x - s.r.bl.x) * (s.r.tr.y - s.r.bl.y);
        }
  }
int main(void)
  {
     union shape myshape;

     myshape.c.r = 2;
     myshape.c.o.x = 1;
     myshape.c.o.y = 1;
     printf("The area of the circle is %f\n", area(myshape, CIRCLE));
     myshape.r.tr.x = 1;
     myshape.r.tr.y = 1;
     myshape.r.bl.x = -1;
     myshape.r.bl.y = -1;
     printf("The area of the rectangle is %f\n", area(myshape, RECTANGLE));
     getch();
     return 0; 
  }
