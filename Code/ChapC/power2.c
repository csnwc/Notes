// 1st few powers of 2 are printed.

#include <stdio.h>

int main(void)
{
   int   i = 0, power = 1;

   while (++i <= 10){
      printf("%5i", power *= 2);
   }
   printf("\n");
   return 0;
}
