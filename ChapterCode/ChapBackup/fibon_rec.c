#include <stdio.h>

int fibonacci(int n);

int main(void)
{

   int i;

   for(i=1; i<45; i++){
      printf("%d = %d\n", i, fibonacci(i));
   }   

   return 0;

}

int fibonacci(int n)
{
   if(n <= 2){
      return 1;
   }
   return( fibonacci(n-1) + fibonacci(n-2) );
}
