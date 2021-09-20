#include <stdio.h>

int main(void)
{
   int i, sum, n=10 ;
   sum = 0;
   for(i = 1; i <= n; ++i){
      sum += i;
   }
   printf("Sum = %d\n", sum);
}
