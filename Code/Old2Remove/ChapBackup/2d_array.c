#include <stdio.h>

/* number of rows */
#define M 3
/* number of columns */
#define N 4

int main(void)
{

   int a[M][N], i, j, sum = 0;
   putchar('\n');
   /* fill array */
   for (i = 0; i < M; ++i){
      for (j = 0; j < N; ++j){
         a[i][j] = i + j;
      }
   }
   /* array values */
   for (i = 0; i < M; ++i){
      for (j = 0; j < N; ++j){
         printf("a[%d][%d] = %d ", i, j, a[i][j]);
      }
      printf("\n");
   }
   /* sum the array */
   for (i = 0; i < M; ++i){
      for (j = 0; j < N; ++j){
         sum += a[i][j];
      }
   }
   printf("\nsum = %d\n\n", sum);
   return 0;
}
