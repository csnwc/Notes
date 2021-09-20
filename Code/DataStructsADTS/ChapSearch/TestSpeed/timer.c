#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

   clock_t c1, c2;
   int i, j;


   c1 = clock();
   for(i=0; i<10000000; i++){
      j = i * 2;
   }
   c2 = clock();
   printf("%f\n", (double)(c2-c1)/(double)(CLOCKS_PER_SEC));

   return 0;

}
