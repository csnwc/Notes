#include <stdio.h>

int main(void)
{
   int   x, y, z;

   printf("Input three integers:  ");
   if(scanf("%d%d%d", &x, &y, &z) != 3){
      printf("Didn't get 3 numbers?\n");
      return 1;
   }
   int min;
   min = (x < y) ? x : y;
   min = (z < min) ? z : min;
   printf("The minimum value is %d\n", min);
   return 0;
}
