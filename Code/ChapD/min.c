#include <stdio.h>

int main(void)
{
   int   x, y, z;

   printf("Input three integers:  ");
   if(scanf("%i%i%i", &x, &y, &z) != 3){
      printf("Didn't get 3 numbers?\n");
      return 1;
   }
   int min;
   if (x < y){
      min = x;
   }
   // Nasty, dropped braces:
   else
      min = y;
   if (z < min){
      min = z;
   }
   printf("The minimum value is %i\n", min);
   return 0;
}
