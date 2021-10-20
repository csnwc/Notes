#include <stdio.h>
#include <time.h>

#define MAXFIB 45

int fibonacci(int n);

int main(void)
{

   clock_t start = clock();
   for(int i=1; i<MAXFIB; i++){
      int j = fibonacci(i);
      printf("%3i, %ld, %i\n", i, clock()-start, j);
   }

   return 0;

}

int fibonacci(int n)
{
   if(n == 1) return 1;
   if(n == 2) return 1;
   return( fibonacci(n-1)+fibonacci(n-2));
}
