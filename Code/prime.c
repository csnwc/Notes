#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int isprime(int n);

int main(void)
{

   assert(isprime(-1) == 0);
   assert(isprime(1) == 0);
   assert(isprime(2) == 1);
   assert(isprime(3) == 1);
   assert(isprime(5) == 1);
   assert(isprime(9) == 0);
   assert(isprime(97) == 1);

   return EXIT_SUCCESS;
}

int isprime(int n)
{

   int i;
   if(n < 2){
      return 0;
   }

   for(i=2; i<n/2; i++){
      if((n%i)==0){
         return 0;
      }
   }

   return 1;
}
