#include <stdio.h>

#define N 500

int main(void)
{

   /* allocate space a[0]...a[N-1] */
   int a[N];
   int i, sum = 0;
   /* fill array */
   for (i = 0; i < N; ++i){
      a[i] = 7 + i * i;
   }
   /* print array */
   for (i = 0; i < N; ++i){
      printf("a[%d]=%d ", i, a[i]);
   }
   /* sum elements */
   for (i = 0; i < N; ++i){
      sum += a[i];
   }
   /* print sum */
   printf("\nsum=%d\n", sum);
   return 0;
}
