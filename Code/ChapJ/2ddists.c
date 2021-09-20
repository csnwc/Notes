#include <stdio.h>
#include <math.h>

#define   M   7
#define   N   9

int main(void)
{
   int   a[M][N];

   // Fill Array
   for (int j = 0; j < M; ++j){
      double y = ((double)j - ((double)(M-1)/2.0));
      for(int i = 0; i < N; ++i){
         double x = ((double)i - ((double)(N-1)/2.0));
         a[j][i] = round(sqrt(x*x + y*y));
      } 
   } 

   // Print Array
   for (int j = 0; j < M; j++){
      for(int i = 0; i < N; i++){
         printf("%d", a[j][i]);
      }
      printf("\n");
   }
   printf("\n");

   return 0;
}
