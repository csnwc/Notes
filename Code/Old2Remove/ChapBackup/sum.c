#include <stdio.h>

int main(void)
{
   int i, sum, n=10 ;
   for(sum = 0 , i = 1; i <= n; ++i)
      sum += i;
   printf("Sum = %d\n", sum);
}
