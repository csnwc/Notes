#include <stdio.h>

int main(void)
{

int x, y, z, min;

   printf("Input three integers: ");
   scanf("%d%d%d", &x, &y, &z);

   if (x < y)
      min = x;
   else
      min = y;
   if (z < min)
      min = z;
   printf("The minimum value is %d\n", min);
   return 0;
}
