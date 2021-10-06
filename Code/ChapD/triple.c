// Triples of integers that sum to N
#include <stdio.h>

#define N 7

int main(void)
{
   int   cnt = 0, i, j, k;

   for(i = 0; i <= N; i++){
      for(j = 0; j <= N; j++){
         for(k = 0; k <= N; k++){
            if(i + j + k == N){
               ++cnt;
               printf("%3i%3i%3i\n", i, j, k);
            }
         }
      }
   }
   printf("\nCount: %i\n", cnt);
   return 0;
}
