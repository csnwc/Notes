// 1st N powers of 2 are printed.

#define N 10

#include <stdio.h>

int main(void)
{
   int   i = 0, power = 1;

   while (i++ <= N){
      power = power * 2;
      printf("%5i", power);
   }
   printf("\n");
   return 0;
}
