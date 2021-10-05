#include <stdio.h>

int main(void)
{

   float x = 5, y = 8, *p;
   p = &x;
   y = *p;
 
   printf("x=%f y=%f\n", x, y);
   return 0;
}
