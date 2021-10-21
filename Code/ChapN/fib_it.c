#include <stdio.h>

#define MAXFIB 24

int fibonacci(int n);

int main(void)
{

   for(int i=1; i<=MAXFIB; i++){
      printf("%d = %d\n", i, fibonacci(i));
   }

   return 0;

}

int fibonacci(int n)
{
   if(n <= 2){
      return 1;
   }
   int a = 1;
   int b = 1;                                                         
   int next;
   for(int i=3; i<=n; i++){
      next = a + b;
      a = b;
      b = next;
   }
   return b;
}
