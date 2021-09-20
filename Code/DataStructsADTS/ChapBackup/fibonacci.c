#include <stdio.h>

int fibonacci(int n);

int main(void)
{

   int i;

   for(i=01; i<20; i++){
      printf("%d = %d\n", i, fibonacci(i));
   }   

   return 0;

}

int fibonacci(int n)
{

   int i, a, b, temp;

   if(n == 1) return 1;
   if(n == 2) return 1;

   a = 1; b = 1;
   for(i=3; i<=n; i++){
      temp = a;
      a = b;
      b = temp + a;
   }

   return b;

}

/*
int fibonacci(int n)
{

   if(n == 1) return 1;
   if(n == 2) return 1;
   
   return( fibonacci(n-1) + fibonacci(n-2) );

}
*/
