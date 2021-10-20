#include <stdio.h>

#define MAXFIB 25

int fibonacci(int n);

int main(void)
{

   for(int i=1; i<MAXFIB; i++){
      printf("%d = %d\n", i, fibonacci(i));
   }

   return 0;

}

int fibonacci(int n)
{
   if(n == 1) return 1;
   if(n == 2) return 1;
   return( fibonacci(n-1)+fibonacci(n-2));
}
