#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CSEC (double)(CLOCKS_PER_SEC)
#define BIGLOOP 1000000000

int main(void)
{

   clock_t c1 = clock();
   for(int i=0; i<BIGLOOP; i++){
        int j = i * 2;
   }
   clock_t c2 = clock();
   printf("%f\n", (double)(c2-c1)/CSEC);
   return 0;

}
