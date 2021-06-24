#include <stdio.h>
#include <math.h>

int main(void)
{
   int i = 4;
   int k = (int) pow( (double)i, 3.0);
   printf("%d^3 = %d\n", i, k);
   return 0;
}
